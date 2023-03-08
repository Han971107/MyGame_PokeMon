#pragma once
#include "pokeScene.h"

namespace poke
{
    class BackGround;
    class Animator;

    class IntroScene : public Scene
    {
    public:
        IntroScene();
        ~IntroScene();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;
        virtual void Release() override;

        virtual void OnEnter() override;
        virtual void OnExit() override;

    private:
        BackGround* mBg;
        Animator* mAnimator;
    };
}

