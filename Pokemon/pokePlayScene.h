#pragma once
#include "pokeScene.h"

namespace poke
{
	class BackGround;

    class PlayScene : public Scene
    {
    public:
		PlayScene();
		virtual ~PlayScene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		virtual void OnEnter();
		virtual void OnExit();

    private:
		BackGround* mBg;
    };
}
