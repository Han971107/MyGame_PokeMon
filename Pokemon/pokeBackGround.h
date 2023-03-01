#pragma once
#include "pokeGameObject.h"
#include "pokeResourceManager.h"

namespace poke
{
    class Image;

    class BackGround : public GameObject
    {
    public:
        BackGround();
        virtual ~BackGround();

        virtual void Initialize() override;
        virtual void Update() override;
        virtual void Render(HDC hdc) override;
        virtual void Release() override;

        void SetImage(const std::wstring& key, const std::wstring& path);
      

    private:
         Image* mImage;
    };
}

