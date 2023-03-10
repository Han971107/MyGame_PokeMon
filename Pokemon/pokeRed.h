#pragma once
#include "pokeGameObject.h"
#include "pokeImage.h"

namespace poke
{
    class Animator;
    class Collider;

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

        void OnCollisionEnter(Collider* other) override;
        void OnCollisionStay(Collider* other) override;
        void OnCollisionExit(Collider* other) override;


    private:
        // 함수 이름이 앞에 소문자인건 private 이라는 뜻이다
        void Idle();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        // test용으로 만든 함수
        void idleCompleteEvent();

    private:
        Animator* mAnimator;
        Collider* mCollider;
        eRedState mState;
        
    };
}
