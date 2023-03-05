#pragma once
#include "pokeGameObject.h"
#include "pokeImage.h"

namespace poke
{
    class Animator;

    class Red : public GameObject
    {
    public:
        enum class eRedState
        {
            Idle,
            move_Left,
            move_Right,
            move_Up,
            move_Down
        };

        Red();
        ~Red();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;
        virtual void Release() override;


    private:
        void Idle();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

    private:
        Animator* mAnimator;
        eRedState mState;
    };
}
