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
	{
		mAnimator = AddComponent<Animator>();
		mCollider = AddComponent<Collider>();
		mState = eRedState::Idle;
	}

	Red::~Red()
	{
		
	}

	void Red::Initialize()
	{
		Transform* tr = GetComponent<Transform>();
		mCollider->SetSize(Vector2{ 60.f, 80.f });
		mCollider->SetCenter(Vector2{ -30.0f, -80.0f });
		mCollider->SetColliderPos(tr->GetPos());

		Image* mImage = ResourceManager::Load<Image>(L"Red", L"..\\Resources\\PlayerStage1.bmp");
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

		// Play
		//mAnimator->GetCompleteEvent(L"ForwardIdle") = std::bind(&Red::idleCompleteEvent, this);
		mAnimator->RedPlay(L"ForwardIdle", true);


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

	void Red::OnCollisionEnter(Collider* other)
	{
		if (other->GetColliderName() == L"PlaySceneDoor")
		{
			SceneManager::LoadScene(eSceneType::Play);
		}
	}

	void Red::OnCollisionStay(Collider* other)
	{

	}

	void Red::OnCollisionExit(Collider* other)
	{

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
			mAnimator->RedPlay(L"LeftRun", true);
			pos.x -= 120.0f * Time::DeltaTime();
		}
		if (Input::GetKeyUp(eKeyCode::LEFT)) {
			mState = eRedState::Idle;
			mAnimator->RedPlay(L"LeftIdle", false);
		}

		if (Input::GetKeyDown(eKeyCode::DOWN)) {
			mState = eRedState::move_Down;
			mAnimator->RedPlay(L"ForwardRun", true);
		}

		tr->SetPos(pos);
	}

	void Red::moveRight()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyHold(eKeyCode::RIGHT))
		{
			mAnimator->RedPlay(L"RightRun", true);
			pos.x += 120.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyUp(eKeyCode::RIGHT)) {
			mState = eRedState::Idle;
			mAnimator->RedPlay(L"RightIdle", false);
		}

		if (Input::GetKeyDown(eKeyCode::LEFT)) {
			mState = eRedState::move_Left;
			mAnimator->RedPlay(L"LeftRun", true);
		}

		if (Input::GetKeyDown(eKeyCode::DOWN)) {
			mState = eRedState::move_Down;
			mAnimator->RedPlay(L"ForwardRun", true);
		}

		tr->SetPos(pos);
	}

	void Red::moveUp()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyHold(eKeyCode::UP))
		{
			mAnimator->RedPlay(L"BackRun", true);
			pos.y -= 120.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyUp(eKeyCode::UP)) {
			mState = eRedState::Idle;
			mAnimator->RedPlay(L"BackIdle", false);
		}

		if (Input::GetKeyDown(eKeyCode::DOWN)) {
			mState = eRedState::move_Down;
			mAnimator->RedPlay(L"ForwardRun", true);
		}

		tr->SetPos(pos);
	}

	void Red::moveDown()
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();

		if (Input::GetKeyHold(eKeyCode::DOWN))
		{
			mAnimator->RedPlay(L"ForwardRun", true);
			pos.y += 120.0f * Time::DeltaTime();
		}
		else if (Input::GetKeyUp(eKeyCode::DOWN)) {
			mState = eRedState::Idle;
			mAnimator->RedPlay(L"ForwardIdle", false);
		}

		tr->SetPos(pos);
	}

	void Red::idleCompleteEvent()
	{
		int a = 0;
	}

}
