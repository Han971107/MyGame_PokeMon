#include "pokePlayScene.h"
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
	PlayScene::PlayScene()
	{

	}

	PlayScene::~PlayScene()
	{

	}

	void PlayScene::Initialize()
	{
		Scene::Initialize();

		mBg = Object::Instantiate<BackGround>(eLayerType::BG);
		mBg->SetName(L"PlayScene");
		mBg->SetImage(L"PlayScene", L"..\\Resources\\PlayScene.bmp");
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

	void PlayScene::Update()
	{
		Scene::Update();
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void PlayScene::Release()
	{
		Scene::Release();
	}

	void PlayScene::OnEnter()
	{
		mRed->GetComponent<Animator>()->Play(L"ForwardIdle", false);
		mRed->SetRedState(poke::Red::eRedState::Idle);
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::BG, true);
	}

	void PlayScene::OnExit()
	{
		mRed->GetComponent<Transform>()->SetPos(Vector2{ 170.0f, 250.0f });
	}
}