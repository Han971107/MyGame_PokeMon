#include "pokeTitleScene.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeBackGround.h"
#include "pokeTransform.h"


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
		//mBg->GetComponent<Transform>()->SetScale(Vector2{ 0.1f, 1.0f });
		AddGameObject(mBg, eLayerType::BG);

		Scene::Initialize();
	}

	void TitleScene::Update()
	{
		if (Input::GetKeyState(eKeyCode::N) == eKeyState::Down)
		{
			SceneManager::LoadScene(eSceneType::Play);
		}

		Scene::Update();
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