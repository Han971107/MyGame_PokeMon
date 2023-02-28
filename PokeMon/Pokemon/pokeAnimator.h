#pragma once
#include "pokeComponent.h"
#include "pokeAnimation.h"
#include "pokeImage.h"

namespace poke
{
    class Animator : public Component
    {
    public:
        struct Event
        {
            void operator=(std::function<void()> func)
            {
                mEvent = std::move(func);
            }

            void operator()()
            {
                if (mEvent)
                    mEvent();
            }

            // void(*name)(int, int)
            std::function<void()> mEvent;
        };

        struct Events
        {
            Event mStartEvent;
            Event mCompleteEvent;
            Event mEndEvent;

            // mStartEvent();
            // mStartEvent = test;
        };

        Animator();
        ~Animator();

        virtual void Initialize();
        virtual void Update();
        virtual void Render(HDC hdc);
        virtual void Release();
     
        void CreateAnimation();
        void CreateAnimations();

        Animation* FindAnimation(const std::wstring& name);
        void Play(const std::wstring& name, bool loop);

        Events* FindEvents(const std::wstring& name);
        std::function<void>& GetStartEvent(const std::wstring& name);
        std::function<void>& GetCompleteEvent(const std::wstring& name);
        std::function<void>& GetEndEvent(const std::wstring& name);

    private:
        std::map<std::wstring, Animation*> mAnimations;
        std::map<std::wstring, Events*> mEvents;
        Animation* mActiveAnimation;
        Image* mSpriteSheet;
    };
}

