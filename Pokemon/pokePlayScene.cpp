#include "pokePlayScene.h"
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
		mBg->SetName(L"PlayImage");
		mBg->SetImage(L"PlayImage", L"..\\Resources\\PlayScene.bmp");
		mBg->GetComponent<Transform>()->SetScale(Vector2{ 2.0f, 2.0f });
	}

	void PlayScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(eSceneType::Home);
		}
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
	}

	void PlayScene::OnExit()
	{
	}
}