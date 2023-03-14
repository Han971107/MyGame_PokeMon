#include "pokeCamera.h"
#include "pokeApplication.h"
#include "pokeGameObject.h"
#include "pokeTransform.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeResourceManager.h"
#include "pokeImage.h"


extern poke::Application application;


namespace poke
{
	Vector2 Camera::mResolution = Vector2::Zero;
	Vector2 Camera::mLookPosition = Vector2::Zero;
	Vector2 Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;
	Image* Camera::mVeilTex = nullptr;
	std::list<tCamEffect> Camera::mListCamEffect = {};


	void Camera::Initialize()
	{
		// 카메라 초기값 오류 수정
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
		mVeilTex = ResourceManager::Load<Image>(L"VeilText", L"..\\Resources\\FadeOut.bmp");
	}

	void Camera::Update()
	{
		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->GetComponent<Transform>()->GetPos();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::Render(HDC hdc)
	{
		if (mListCamEffect.empty())
			return;

		// 시간 누적값을 체크해서
		tCamEffect& effect = mListCamEffect.front();
		effect.curTime += Time::DeltaTime();

		float ratio = 0.f;								// 이펙트 진행 비율
		ratio = effect.curTime / effect.EffectDuration;

		if (ratio < 0.f)
			ratio = 0.f;
		if (ratio > 1.f)
			ratio = 1.f;


		int iAlpha = 0;

		if (CAM_EFFECT::Fade_OUT == effect.Effect)
		{		
			iAlpha = (int)(255.f * ratio);	
		}
		else if (CAM_EFFECT::Fade_IN == effect.Effect)
		{
			iAlpha = (int)(255.f * (1.f - ratio));
		}


		BLENDFUNCTION bf = {};

		bf.BlendOp = AC_SRC_OVER;
		bf.BlendFlags = 0;
		bf.AlphaFormat = 0;
		bf.SourceConstantAlpha = iAlpha;

		AlphaBlend(hdc
				, 0, 0
				, mVeilTex->GetWidth(), mVeilTex->GetHeight()
				, mVeilTex->GetHdc()
				, 0, 0
				, mVeilTex->GetWidth(), mVeilTex->GetHeight(), bf);


		// 진행 시간이 이펙트 최대 지정 시간을 넘어선 경우
		if (effect.EffectDuration < effect.curTime)
		{
			// 효과 종료
			mListCamEffect.pop_front();
		}
	}

	void Camera::Clear()
	{
		mResolution.x = application.GetWidth();
		mResolution.y = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
		mDistance = Vector2::Zero;
	}

}