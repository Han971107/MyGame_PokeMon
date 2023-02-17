#pragma once
#include "pokeGameObject.h"


namespace poke
{
    class Red : public GameObject
    {
    public:

        Red();
        ~Red();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;
        virtual void Release() override;

    private:

    };
}
