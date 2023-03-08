#include "pokeIntroScene.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeResourceManager.h"
#include "pokeBackGround.h"
#include "pokeAnimator.h"
#include "pokeTransform.h"


namespace poke
{
	IntroScene::IntroScene()
	{
		mBg = new BackGround();
		mBg->SetName(L"IntroScene");
		mBg->SetImage(L"IntroScene", L"..\\Resources\\IntroScene.bmp");
		mBg->GetComponent<Transform>()->SetScale(Vector2{ 1.4f, 2.0f });
		AddGameObject(mBg, eLayerType::BG);
	}

	IntroScene::~IntroScene()
	{
	}

	void IntroScene::Initialize()
	{
		mAnimator = mBg->AddComponent<Animator>();
		mAnimator->CreateAnimation(L"IntroScene", mBg->GetImage(), Vector2::Zero, 4, 2, 4, Vector2{ 280.f, 1.0f}, 1.5f);
		mAnimator->Play(L"IntroScene", true);

		Scene::Initialize();
	}

	void IntroScene::Update()
	{
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(eSceneType::Title);
		}

		Scene::Update();
	}

	void IntroScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
	}

	void IntroScene::Release()
	{
		Scene::Release();
	}

	void IntroScene::OnEnter()
	{

	}

	void IntroScene::OnExit()
	{

	}

}