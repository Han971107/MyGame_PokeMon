#include "pokePlayScene.h"
#include "pokeRed.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeCollider.h"
#include "pokeBackGround.h"
#include "pokeTransform.h"
#include "pokeCollisionManager.h"
#include "pokeCamera.h"


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
		mBg = new BackGround();
		mBg->SetName(L"PlayScene");
		mBg->SetImage(L"PlayScene", L"..\\Resources\\PlayScene.bmp");
		Collider* collider = mBg->AddComponent<Collider>();
		collider->SetSize(Vector2{ 100.f, 50.f });
		collider->SetCenter(Vector2{ 180.f, 550.f });
		AddGameObject(mBg, eLayerType::BG);

		mRed = new Red();
		mRed->SetName(L"Player");
		AddGameObject(mRed, eLayerType::Player);

		// 카메라 타겟을 플레이어로 고정
		//Camera::SetTarget(mRed);

		CollisionManager::SetLayer(eLayerType::Player, eLayerType::BG, true);
		
		Scene::Initialize();
	}

	void PlayScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

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
		CollisionManager::SetLayer(eLayerType::Player, eLayerType::BG, true);
	}

	void PlayScene::OnExit()
	{
		//mRed->SetPos(Vector2{ 0.0f, 0.0f });
	}
}