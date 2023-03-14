#include "pokeTitleScene.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeAnimBackGround.h"
#include "pokeTransform.h"
#include "pokeObject.h"
#include "pokeAnimator.h"


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

		mAbg = Object::Instantiate<AnimBackGround>(eLayerType::BG);
		mAbg->GetComponent<Transform>()->SetScale(Vector2{ 3.2f, 3.4f });

		mAnimator = mAbg->AddComponent<Animator>();
		mAbg->SetAnimator(mAnimator);
		mAnimator->CreateAnimations(L"..\\Resources\\TitleImage\\", Vector2{ 130.f, 1.0f }, 0.07f);
		mAnimator->Play(L"TitleImage", true);
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