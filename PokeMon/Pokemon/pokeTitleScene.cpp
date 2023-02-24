#include "pokeTitleScene.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeBackGround.h"


namespace poke
{
	TitleScene::TitleScene()
	{

	}

	TitleScene::~TitleScene()
	{

	}

	void TitleScene::Initialize()
	{
		mBg = new BackGround();
		mBg->SetName(L"TitleScene");
		mBg->SetImage(L"TitleScene", L"..\\Resources\\TitleScene.bmp");
		AddGameObject(mBg, eLayerType::BG);

		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void TitleScene::Release()
	{
		Scene::Release();
	}

	void TitleScene::OnEnter()
	{

	}

	void TitleScene::OnExit()
	{

	}
}