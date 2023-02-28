#include "pokeRed.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeResourceManager.h"
#include "pokeTransform.h"


namespace poke
{
	Red::Red()
		: mImage(nullptr)
		, mTime(0.0f)
		, mIdx(0)
	{

	}

	Red::~Red()
	{

	}

	void Red::Initialize()
	{
		mImage = ResourceManager::Load<Image>(L"red", L"..\\Resources\\PlayerStage.bmp");
		GameObject::Initialize();
	}

	void Red::Update()
	{
		GameObject::Update();

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyState(eKeyCode::LEFT) == eKeyState::Pressed)
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::RIGHT) == eKeyState::Pressed)
		{
			pos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::UP) == eKeyState::Pressed)
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::DOWN) == eKeyState::Pressed)
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetPos(pos);
	}

	void Red::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		mTime += Time::DeltaTime();

		if (mIdx >= 4)
		{
			mIdx = 0;
		}

		if (mTime > 0.5f)
		{
			++mIdx;
			mTime = 0.0f;
		}

		TransparentBlt(hdc, pos.x, pos.y, 64, 80
				, mImage->GetHdc(), (64 * mIdx), 0, 64, 80, RGB(255, 0, 255));
		//BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}

	void Red::Release()
	{
		GameObject::Release();
	}
}
