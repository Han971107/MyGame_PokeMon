#include "pokeSceneManager.h"
#include "pokeIntroScene.h"
#include "pokeHomeScene.h"
#include "pokeTitleScene.h"
#include "pokePlayScene.h"
#include "pokeCollisionManager.h"
#include "pokeCamera.h"


namespace poke
{
	std::vector<Scene*> SceneManager::mScenes = {};
	Scene* SceneManager::mActiveScene = nullptr;

	void SceneManager::Initialize()
	{
		mScenes.resize((UINT)eSceneType::End);

		mScenes[(UINT)eSceneType::Intro] = new IntroScene();
		mScenes[(UINT)eSceneType::Intro]->SetName(L"IntroScene");
		mScenes[(UINT)eSceneType::Title] = new TitleScene();
		mScenes[(UINT)eSceneType::Title]->SetName(L"TitleScene");
		mScenes[(UINT)eSceneType::Home] = new HomeScene();
		mScenes[(UINT)eSceneType::Home]->SetName(L"HomeScene");
		mScenes[(UINT)eSceneType::Play] = new PlayScene();
		mScenes[(UINT)eSceneType::Play]->SetName(L"PlayScene");

		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			scene->Initialize();
		}

		mActiveScene = mScenes[(UINT)eSceneType::Intro];
	}

	void SceneManager::Update()
	{
		mActiveScene->Update();
	}

	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
	}

	void SceneManager::Destroy()
	{

	}

	void SceneManager::Release()
	{
		for (Scene* scene : mScenes)
		{
			if (scene == nullptr)
				continue;

			delete scene;
			scene = nullptr;
		}
	}

	void SceneManager::LoadScene(eSceneType type)
	{
		Camera::Clear();

		// ÇöÀç¾À
		mActiveScene->OnExit();

		CollisionManager::Clear();

		// ´ÙÀ½¾À
		mActiveScene = mScenes[(UINT)type];
		mActiveScene->OnEnter();
	}
}