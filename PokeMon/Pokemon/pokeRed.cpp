#include "pokeRed.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeResourceManager.h"


namespace poke
{
	Red::Red()
	{

	}

	Red::~Red()
	{

	}

	void Red::Initialize()
	{
		mImage = ResourceManager::Load<Image>(L"Red", L"..\\Resources\\Idle.bmp");
		GameObject::Initialize();
	}

	void Red::Update()
	{
		GameObject::Update();

		if (Input::GetKeyState(eKeyCode::LEFT) == eKeyState::Hold)
		{
			mPos.x -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::RIGHT) == eKeyState::Hold)
		{
			mPos.x += 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::UP) == eKeyState::Hold)
		{
			mPos.y -= 100.0f * Time::DeltaTime();
		}

		if (Input::GetKeyState(eKeyCode::DOWN) == eKeyState::Hold)
		{
			mPos.y += 100.0f * Time::DeltaTime();
		}
	}

	void Red::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		
		BitBlt(hdc, mPos.x, mPos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}

	void Red::Release()
	{
		GameObject::Release();
	}
}
