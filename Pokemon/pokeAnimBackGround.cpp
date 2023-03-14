#include "pokeAnimBackGround.h"
#include "pokeTransform.h"
#include "pokeAnimator.h"
#include "pokeSceneManager.h"

namespace poke
{
	AnimBackGround::AnimBackGround()
		: mImage(nullptr)
		, mAnimator(nullptr)
	{
	}

	AnimBackGround::~AnimBackGround()
	{
	}

	void AnimBackGround::Initialize()
	{
		GameObject::Initialize();
	}

	void AnimBackGround::Update()
	{
		GameObject::Update();
	}

	void AnimBackGround::Render(HDC hdc)
	{
		mAnimator->GetActiveAnimation()->AnimBackGroundRender(hdc);
	}

	void AnimBackGround::Release()
	{
		GameObject::Release();
	}

	void AnimBackGround::SetImage(const std::wstring& key, const std::wstring& path)
	{
		mImage = ResourceManager::Load<Image>(key, path);
	}

	void AnimBackGround::CallIntroAnimCompleteEvent()
	{
		//mAnimator->GetCompleteEvent(L"IntroImage") = std::bind(&AnimBackGround::introAnimCompleteEvent, this);
		introAnimCompleteEvent();
	}

	void AnimBackGround::introAnimCompleteEvent()
	{
		SceneManager::LoadScene(eSceneType::Title);
	}
}
