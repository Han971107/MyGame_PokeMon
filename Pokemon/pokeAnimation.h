#pragma once
#include "pokeEntity.h"

namespace poke
{
	class Image;
	class Animator;

    class Animation : public Entity
    {
	public:
		struct Sprite
		{
			Vector2 leftTop;
			Vector2 size;
			Vector2 offset;
			float duration;

			Sprite()
				: leftTop(Vector2::Zero)
				, size(Vector2::Zero)
				, offset(Vector2::Zero)
				, duration(0.0f)
			{

			}
		};

		Animation();
		~Animation();

		void Initialize();
		void Update();
		void Render(HDC hdc);
		void AnimBackGroundRender(HDC hdc);
		void CreateSpriteSheet(Image* sheet, Vector2 leftTop, UINT column, UINT row, UINT spriteLength, Vector2 offset, float duration);
		void Reset();

		bool IsComplete() { return mbComplete; }

		void SetAnimator(Animator* animator) { mAnimator = animator; }
		Animator* GetAnimator() { return mAnimator; }

		void SetAnimationName(const std::wstring& name) { mName = name; }
		std::wstring& GetAnimationName() { return mName; }

	private:
		Animator* mAnimator;
		Image* mSheetImage;
		std::vector<Sprite> mSpriteSheet;
		std::wstring mName;
		float mTime;
		bool mbComplete;
		int mSpriteIndex;
    };
}

