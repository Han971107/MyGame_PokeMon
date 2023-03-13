#pragma once
#include "pokeComponent.h"

namespace poke
{
    class Collider : public Component
    {
    public:
        Collider();
        ~Collider();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;
        virtual void Release() override;

        void SetCenter(Vector2 center) { mCenter = center; }
        void SetSize(Vector2 size) { mSize = size; }

        void OnCollisionEnter(Collider* other);
        void OnCollisionStay(Collider* other);
        void OnCollisionExit(Collider* other);

        Vector2 GetPos() { return mPos; }
        Vector2 GetSize() { return mSize; }   

        void SetColliderPos(Vector2 pos) { mPos = pos; }
        void SetColliderName(const std::wstring& colliderName) { mColliderName = colliderName; }
        std::wstring& GetColliderName() { return mColliderName; }
         
    private:
        static UINT ColliderNumber;
        UINT mID;
        Vector2 mCenter;
        Vector2 mPos;
        Vector2 mSize;

        std::wstring mColliderName;
    };
}
