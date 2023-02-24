#pragma once
#include "pokeScene.h"


namespace poke
{
	class BackGround;
	class Red;

	class PlayScene : public Scene
	{
	public:

		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		Red* mRed;
		BackGround* mBg;
	};
}

