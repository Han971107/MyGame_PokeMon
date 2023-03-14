#pragma once
#include "pokeGameObject.h"
#include "pokeResourceManager.h"

namespace poke
{
    class Image;
    class Animator;

    class AnimBackGround : public GameObject
    {  
        public:
            AnimBackGround();
            virtual ~AnimBackGround();

            virtual void Initialize() override;
            virtual void Update() override;
            virtual void Render(HDC hdc) override;
            virtual void Release() override;

            void SetImage(const std::wstring& key, const std::wstring& path);
            Image* GetImage() const { return mImage; }

            Animator* GetAnimator() { return mAnimator; }
            void SetAnimator(Animator* animator) { mAnimator = animator; }

            // IntroScene
            void CallIntroAnimCompleteEvent();

        private:
            // IntroScene
            void introAnimCompleteEvent();

        private:
            Image* mImage;
            Animator* mAnimator;
    };
}

