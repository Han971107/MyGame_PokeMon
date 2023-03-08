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
        void SetScale(Vector2 pos) { mScale = pos; }

        Vector2 GetPos() { return mPos; }
        Vector2 GetSize() { return mSize; }     
         
    private:
        Vector2 mCenter;
        Vector2 mScale;
        Vector2 mPos;
        Vector2 mSize;
    };
}
