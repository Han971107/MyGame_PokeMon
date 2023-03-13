#include "pokeTitleScene.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeBackGround.h"
#include "pokeTransform.h"
#include "pokeObject.h"


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
		Scene::Initialize();

		mBg = Object::Instantiate<BackGround>(eLayerType::BG);
		mBg->SetName(L"TitleImage");
		mBg->SetImage(L"TitleImage", L"..\\Resources\\TitleScene.bmp");	
	}

	void TitleScene::Update()
	{
		Scene::Update();

		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(eSceneType::Home);
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