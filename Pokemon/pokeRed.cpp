#include "pokeRed.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeResourceManager.h"
#include "pokeTransform.h"
#include "pokeAnimator.h"


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
		Image* mImage = ResourceManager::Load<Image>(L"Red", L"..\\Resources\\PlayerStage.bmp");
		Animator* animator = AddComponent<Animator>();
		animator->CreateAnimation(L"LeftRun", mImage, Vector2::Zero, 4, 4, 4, Vector2::Zero, 0.1);

		animator->Play(L"LeftRun", true);

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
	}

	void Red::Release()
	{
		GameObject::Release();
	}
}
