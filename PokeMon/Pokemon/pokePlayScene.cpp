#include "pokePlayScene.h"
#include "pokeRed.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"


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
		mRed = new Red();
		mRed->SetName(L"Player");
		AddGameObject(mRed, eLayerType::Player);

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

	}

	void PlayScene::OnExit()
	{
		//mRed->SetPos(Vector2{ 0.0f, 0.0f });
	}
}