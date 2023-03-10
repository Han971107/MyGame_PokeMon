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
        // �Լ� �̸��� �տ� �ҹ����ΰ� private �̶�� ���̴�
        void Idle();
        void moveLeft();
        void moveRight();
        void moveUp();
        void moveDown();

        // test������ ���� �Լ�
        void idleCompleteEvent();

    private:
        Animator* mAnimator;
        Collider* mCollider;
        eRedState mState;
        
    };
}
