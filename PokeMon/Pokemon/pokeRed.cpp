#include "pokeRed.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeResourceManager.h"
#include "pokeTransform.h"


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
		mImage = ResourceManager::Load<Image>(L"red", L"..\\Resources\\Idle.bmp");
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
		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}

	void Red::Release()
	{
		GameObject::Release();
	}
}
