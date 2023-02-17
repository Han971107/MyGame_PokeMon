#pragma once
#include "pokeScene.h"

namespace poke
{
	class SceneManager
	{
	public:

		SceneManager();
		virtual ~SceneManager();

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);
		static void Release();

	private:
		static std::vector<Scene*> mScenes;

	};
}

