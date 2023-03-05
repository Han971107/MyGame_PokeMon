#include "pokeRed.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeResourceManager.h"
#include "pokeTransform.h"
#include "pokeAnimator.h"
#include "pokeCollider.h"


namespace poke
{
	Red::Red()
		: mAnimator(nullptr)
	{

	}

	Red::~Red()
	{
		
	}

	void Red::Initialize()
	{
		GetComponent<Transform>()->SetPos(Vector2{200.0f, 200.0f});

		Image* mImage = ResourceManager::Load<Image>(L"Red", L"..\\Resources\\PlayerStage1.bmp");
		mAnimator = AddComponent<Animator>();

		mAnimator->CreateAnimation(L"LeftRun", mImage, Vector2::Zero, 4, 4, 4, Vector2::Zero, 0.2);
		mAnimator->CreateAnimation(L"ForwardRun", mImage, Vector2{ 0.0f, 80.f }, 4, 4, 4, Vector2::Zero, 0.2);
		mAnimator->CreateAnimation(L"BackRun", mImage, Vector2{ 0.0f, 160.f }, 4, 4, 4, Vector2::Zero, 0.2);
		mAnimator->CreateAnimation(L"RightRun", mImage, Vector2{ 0.0f, 240.f }, 4, 4, 4, Vector2::Zero, 0.2);

		// fowardIdle
		mAnimator->CreateAnimation(L"ForwardIdle", mImage, Vector2{ 0.0f, 80.f }, 4, 4, 1, Vector2::Zero, 0.0f);
		// leftIdle
		mAnimator->CreateAnimation(L"LeftIdle", mImage, Vector2{ 0.0f, 0.0f }, 4, 4, 1, Vector2::Zero, 0.0f);
		// rigthIdle
		mAnimator->CreateAnimation(L"RightIdle", mImage, Vector2{ 0.0f, 240.f }, 4, 4, 1, Vector2::Zero, 0.0f);
		// backIdle
		mAnimator->CreateAnimation(L"BackIdle", mImage, Vector2{ 0.0f, 160.f }, 4, 4, 1, Vector2::Zero, 0.0f);

		mAnimator->Play(L"ForwardIdle", false);
		mState = eRedState::Idle;

		mCollider = AddComponent<Collider>();
		mCollider->SetCenter(Vector2{ -50.f, 0.0f });

		GameObject::Initialize();
	}

	void Red::Update()
	{
		GameObject::Update();

		switch (mState)
		{
		case poke::Red::eRedState::Idle:
			Idle();
			break;
		case poke::Red::eRedState::move_Left:
			moveLeft();
			break;
		case poke::Red::eRedState::move_Right:
			moveRight();
			break;
		case poke::Red::eRedState::move_Up:
			moveUp();
			break;
		case poke::Red::eRedState::move_Down:
			moveDown();
			break;
		default:
			break;
		}
	}

	void Red::Render(HDC hdc)
	{
		GameObject::Render(hdc);
	}

	void Red::Release()
	{
		GameObject::Release();
	}

	void Red::Idle()
	{
		if (Input::GetKeyDown(eKeyCode::LEFT))
			mState = eRedState::move_Left;
		else if (Input::GetKeyDown(eKeyCode::RIGHT))
			mState = eRedState::move_Right;
		else if (Input::GetKeyDown(eKeyCode::UP))
			mState = eRedState::move_Up;
		else if (Input::GetKeyDown(eKeyCode::DOWN))
			mState = eRedState::move_Down;
	}

	void Red::moveLeft()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyHold(eKeyCode::LEFT))
		{
			mAnimator->Play(L"LeftRun", true);
			pos.x -= 120.0f * Time::DeltaTime();
		}
		if (Input::GetKeyUp(eKeyCode::LEFT)) {
			mState = eRedState::Idle;
			mAnimator->Play(L"LeftIdle", false);
		}

		if (Input::GetKeyDown(eKeyCode::DOWN)) {
			mState = eRedState::move_Down;
			mAnimator->Play(L"ForwardRun", true);
		}

		tr->SetPos(pos);
	}

	void Red::moveRight()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyHold(eKeyCode::RIGHT))
		{
			mAnimator->Play(L"RightRun", true);
			pos.x += 120.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyUp(eKeyCode::RIGHT)) {
			mState = eRedState::Idle;
			mAnimator->Play(L"RightIdle", false);
		}

		if (Input::GetKeyDown(eKeyCode::LEFT)) {
			mState = eRedState::move_Left;
			mAnimator->Play(L"LeftRun", true);
		}

		if (Input::GetKeyDown(eKeyCode::DOWN)) {
			mState = eRedState::move_Down;
			mAnimator->Play(L"ForwardRun", true);
		}

		tr->SetPos(pos);
	}

	void Red::moveUp()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyHold(eKeyCode::UP))
		{
			mAnimator->Play(L"BackRun", true);
			pos.y -= 120.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyUp(eKeyCode::UP)) {
			mState = eRedState::Idle;
			mAnimator->Play(L"BackIdle", false);
		}

		if (Input::GetKeyDown(eKeyCode::DOWN)) {
			mState = eRedState::move_Down;
			mAnimator->Play(L"ForwardRun", true);
		}

		tr->SetPos(pos);
	}

	void Red::moveDown()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyHold(eKeyCode::DOWN))
		{
			mAnimator->Play(L"ForwardRun", true);
			pos.y += 120.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyUp(eKeyCode::DOWN)) {
			mState = eRedState::Idle;
			mAnimator->Play(L"ForwardIdle", false);
		}

		tr->SetPos(pos);
	}

}
