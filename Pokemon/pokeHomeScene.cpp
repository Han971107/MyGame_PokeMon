#include "pokeHomeScene.h"
#include "pokeRed.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeCollider.h"
#include "pokeBackGround.h"
#include "pokeTransform.h"
#include "pokeCollisionManager.h"
#include "pokeCamera.h"
#include "pokeObject.h"
#include "pokeAnimator.h"


namespace poke
{
	HomeScene::HomeScene()
	{

	}

	HomeScene::~HomeScene()
	{

	}

	void HomeScene::Initialize()
	{
		Scene::Initialize();

		mBg = Object::Instantiate<BackGround>(eLayerType::BG);
		mBg->SetName(L"HomeScene");
		mBg->SetImage(L"HomeScene", L"..\\Resources\\HomeScene.bmp");
		Collider* doorCollider = mBg->AddComponent<Collider>();
		doorCollider->SetSize(Vector2{ 100.f, 50.f });
		doorCollider->SetCenter(Vector2{ 180.f, 550.f });
		doorCollider->SetColliderName(L"PlaySceneDoor");


		mRed = Object::Instantiate<Red>(Vector2{ 170.0f, 250.0f }, eLayerType::Player);
		mRed->SetName(L"Player");

		// 카메라 타겟을 플레이어로 고정
		//Camera::SetTarget(mRed);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::BG, true);
		
	}

	void HomeScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(eSceneType::Play);
		}
	}

	void HomeScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void HomeScene::Release()
	{
		Scene::Release();
	}

	void HomeScene::OnEnter()
	{
		mRed->GetComponent<Animator>()->Play(L"ForwardIdle", false);
		mRed->SetRedState(poke::Red::eRedState::Idle);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::BG, true);
	}

	void HomeScene::OnExit()
	{
		mRed->GetComponent<Transform>()->SetPos(Vector2{ 170.0f, 250.0f });
	}
}