#pragma once
#include "MergeEngine.h"

namespace poke
{
	class GameObject;
	class Image;

	enum class CAM_EFFECT
	{
		Fade_IN,
		Fade_OUT,
		NONE,
	};

	struct tCamEffect
	{
		CAM_EFFECT Effect;
		float EffectDuration;
		float curTime;
	};


	class Camera
	{
	public:

		//Camera();
		//~Camera();

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static void Clear();

		static void SetTarget(GameObject* target) { mTarget = target; }
		static Vector2 CalculatePos(Vector2 pos) { return pos - mDistance; }

		//void SetCamState(CAM_EFFECT effect_type) { Effect = effect_type; }
		//CAM_EFFECT GetCamState() { return Effect; } 

		static void FadeIn(float fDuration)
		{
			tCamEffect ef = {};
			ef.Effect = CAM_EFFECT::Fade_IN;;
			ef.EffectDuration = fDuration;
			ef.curTime = 0.0f;

			mListCamEffect.push_back(ef);

			if (0.f == ef.EffectDuration)
				assert(nullptr);
		}

		static void FadeOut(float fDuration) 
		{
			tCamEffect ef = {};
			ef.Effect = CAM_EFFECT::Fade_IN;;
			ef.EffectDuration = fDuration;
			ef.curTime = 0.0f;

			mListCamEffect.push_back(ef);

			if (0.f == ef.EffectDuration)
				assert(nullptr);
		}

	private:
		//
		static Image* mVeilTex;
		static std::list<tCamEffect> mListCamEffect;

	private:
		static Vector2 mResolution;
		static Vector2 mLookPosition;
		static Vector2 mDistance;
		static GameObject* mTarget;
	};
}
