#include "pokeIntroScene.h"
#include "pokeInput.h"
#include "pokeSceneManager.h"
#include "pokeResourceManager.h"
#include "pokeAnimBackGround.h"
#include "pokeAnimator.h"
#include "pokeTransform.h"
#include "pokeObject.h"


namespace poke
{
	IntroScene::IntroScene()
		: mAbg(nullptr)
		, mAnimator(nullptr)
	{
		
	}

	IntroScene::~IntroScene()
	{
	}

	void IntroScene::Initialize()
	{
		// mAbg -> member Animantion back ground

		Scene::Initialize();

		mAbg = Object::Instantiate<AnimBackGround>(eLayerType::BG);
		mAbg->GetComponent<Transform>()->SetScale(Vector2{ 3.2f, 3.4f });

		mAnimator = mAbg->AddComponent<Animator>();
		mAbg->SetAnimator(mAnimator);
		mAnimator->CreateAnimations(L"..\\Resources\\IntroImage\\", Vector2{ 130.f, 1.0f }, 0.067f); //0.067f

		// 规过(1)
		mAnimator->GetCompleteEvent(L"IntroImage") = std::bind(&AnimBackGround::CallIntroAnimCompleteEvent, mAbg);
		mAnimator->Play(L"IntroImage", true);

		/* 规过(2)
		std::function<void(AnimBackGround*)> func = &AnimBackGround::CallIntroAnimCompleteEvent;
		func(mAbg);*/

		/* 规过(3)
		mAbg->CallIntroAnimCompleteEvent();*/
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