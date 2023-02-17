#pragma once
#include "pokeScene.h"


namespace poke
{
	class PlayScene : public Scene
	{
	public:

		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

	private:

	};
}

