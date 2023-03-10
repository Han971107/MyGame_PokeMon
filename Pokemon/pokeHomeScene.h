#pragma once
#include "pokeScene.h"


namespace poke
{
	class BackGround;
	class Red;
	class Collider;

	class HomeScene : public Scene
	{
	public:

		HomeScene();
		virtual ~HomeScene();

		virtual void Initialize() override;
		virtual void Update() override;
		virtual void Render(HDC hdc) override;
		virtual void Release() override;

		virtual void OnEnter() override;
		virtual void OnExit() override;

	private:
		void resetOnEnter();
		void resetOnExit();

	private:
		Red* mRed;
		BackGround* mBg;
		Collider* mDoorCollider;
	};
}

