#include "pokeAnimator.h"
#include "pokeResourceManager.h"

namespace poke
{
	Animator::Animator()
		: Component(eComponentType::Animator)
		, mActiveAnimation(nullptr)
		, mSpriteSheet(nullptr)
		, mbLoop(false)
	{

	}

	Animator::~Animator()
	{
		for (auto animation : mAnimations)
		{
			delete animation.second;
			animation.second = nullptr;
		}
		for (auto events : mEvents)
		{
			delete events.second;
			events.second = nullptr;
		}
	}

	void Animator::Initialize()
	{
	}

	void Animator::Update()
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Update();

			if (mActiveAnimation->IsComplete())
			{
				if (mbLoop && mActiveAnimation->IsComplete())
				{
					Animator::Events* events
						= FindEvents(mActiveAnimation->GetAnimationName());

					if (events != nullptr)
						events->mCompleteEvent();
				}

				if (mbLoop && mActiveAnimation->IsComplete())
					mActiveAnimation->Reset();
			}
		}
	}

	void Animator::Render(HDC hdc)
	{
		if (mActiveAnimation)
		{
			mActiveAnimation->Render(hdc);
		}
	}

	void Animator::Release()
	{

	}


	//=================================================================================================
	//=================================================================================================
	void Animator::recursive_directory(const std::wstring& path, std::vector<Image*>& images, UINT& width, UINT& height, UINT& fileCount)
	{
		for (const auto& p : std::filesystem::recursive_directory_iterator(path))
		{
			std::wstring fileName = p.path().filename();
			std::wstring fullName = path + L"\\" + fileName;

			const std::wstring ext = p.path().extension();
			if (ext == L".png")
				continue;

			Image* image = ResourceManager::Load<Image>(fileName, fullName);
			images.push_back(image);

			if (width < image->GetWidth())
			{
				width = image->GetWidth();
			}
			if (height < image->GetHeight())
			{
				height = image->GetHeight();
			}
			fileCount++;
		}
	}
	//=================================================================================================
	//=================================================================================================


	//=================================================================================================
	//=================================================================================================
	void Animator::CreateAnimation(const std::wstring& name
		, Image* sheet, Vector2 leftTop
		, UINT column, UINT row, UINT spriteLength
		, Vector2 offset, float duration)
	{
		Animation* animation = FindAnimation(name);

		if (animation != nullptr)
			return;

		animation = new Animation();
		animation->CreateSpriteSheet(sheet, leftTop, column, row, spriteLength, offset, duration);
		animation->SetAnimationName(name);
		animation->SetAnimator(this);

		mAnimations.insert(std::make_pair(name, animation));

		// 애니메이션이 만들어지면서 이벤트도 생성
		Events* event = new Events();
		mEvents.insert(std::make_pair(name, event));
	}
	//=================================================================================================
	//=================================================================================================


	//=================================================================================================
	//=================================================================================================
	void Animator::CreateAnimations(const std::wstring& path, Vector2 offset, float duration)
	{
		UINT width = 0;
		UINT height = 0;
		UINT fileCount = 0;

		std::filesystem::path fs(path);
		std::vector<Image*> images = {};

		recursive_directory(path, images, width, height, fileCount);

		std::wstring key = fs.parent_path().filename();
		key += fs.filename();
		mSpriteSheet = Image::CreateEmptySpriteSheet(key, width * fileCount, height);

		//
		int index = 0;
		for (Image* image : images)
		{
			int cneterX = (width - image->GetWidth()) / 2;
			int cneterY = (height - image->GetHeight());

			BitBlt(mSpriteSheet->GetHdc()
				, width * index + cneterX
				, 0 + cneterY
				, image->GetWidth(), image->GetHeight()
				, image->GetHdc(), 0, 0, SRCCOPY);

			++index;
		}

		CreateAnimation(key, mSpriteSheet, Vector2::Zero, index, 1, index, offset, duration);
	}
	//=================================================================================================
	//=================================================================================================


	//=================================================================================================
	//=================================================================================================
	Animation* Animator::FindAnimation(const std::wstring& name)
	{
		std::map<std::wstring, Animation*>::iterator iter
			= mAnimations.find(name);

		if (iter == mAnimations.end())
			return nullptr;

		return iter->second;
	}
	//=================================================================================================
	//=================================================================================================


	//=================================================================================================
	//=================================================================================================
	void Animator::RedPlay(const std::wstring& name, bool loop)
	{
		mActiveAnimation = FindAnimation(name);
		mbLoop = loop;
	}
	//=================================================================================================
	//=================================================================================================


	//=================================================================================================
	//=================================================================================================
	void Animator::Play(const std::wstring& name, bool loop)
	{
		if (mActiveAnimation != nullptr)
		{
			Animator::Events* prevents
				= FindEvents(mActiveAnimation->GetAnimationName());

			if (prevents != nullptr)
				prevents->mEndEvent();
		}

		mActiveAnimation = FindAnimation(name);
		mActiveAnimation->Reset();
		mbLoop = loop;

		Animator::Events* events
			= FindEvents(mActiveAnimation->GetAnimationName());

		if (events != nullptr)
			events->mStartEvent();
	}
	//=================================================================================================
	//=================================================================================================


	//=================================================================================================
	//=================================================================================================
	Animator::Events* Animator::FindEvents(const std::wstring& name)
	{
		std::map<std::wstring, Events*>::iterator iter
			= mEvents.find(name);

		if (iter == mEvents.end())
			return nullptr;

		return iter->second;
	}
	//=================================================================================================
	//=================================================================================================


	//=================================================================================================
	//=================================================================================================
	std::function<void()>& Animator::GetStartEvent(const std::wstring& name)
	{
		Animation* animation = FindAnimation(name);

		Animator::Events* events
			= FindEvents(animation->GetAnimationName());

		return events->mStartEvent.mEvent;
	}

	std::function<void()>& Animator::GetCompleteEvent(const std::wstring& name)
	{
		Animation* animation = FindAnimation(name);

		Animator::Events* events
			= FindEvents(animation->GetAnimationName());

		return events->mCompleteEvent.mEvent;
	}

	std::function<void()>& Animator::GetEndEvent(const std::wstring& name)
	{
		Animation* animation = FindAnimation(name);

		Animator::Events* events
			= FindEvents(animation->GetAnimationName());

		return events->mEndEvent.mEvent;
	}
	//=================================================================================================
	//=================================================================================================
}