#pragma once
#include "pokeScene.h"

namespace poke
{
	class SceneManager
	{
	public:

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

		static void LoadScene(eSceneType type);

	private:
		static std::vector<Scene*> mScenes;
		static Scene* mActiveScene;
	};
}

