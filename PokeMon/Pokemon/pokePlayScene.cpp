#include "pokePlayScene.h"
#include "pokeRed.h"

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
		for (int i = 0; i < 2; ++i) 
		{
			Red* red = new Red();
			red->SetName(L"Player");
			AddGameObject(red, eLayerType::Player);
		}

		Scene::Initialize();
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
}