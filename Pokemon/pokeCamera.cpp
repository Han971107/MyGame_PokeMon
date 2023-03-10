#include "pokeCamera.h"
#include "pokeApplication.h"
#include "pokeGameObject.h"
#include "pokeTransform.h"
#include "pokeTime.h"
#include "pokeInput.h"


extern poke::Application application;


namespace poke
{
	Vector2	Camera::mResolution = Vector2::Zero;
	Vector2	Camera::mLookPosition = Vector2::Zero;
	Vector2	Camera::mDistance = Vector2::Zero;
	GameObject* Camera::mTarget = nullptr;

	void Camera::Initialize()
	{
		mResolution.x = application.GetWidth();
		mResolution.x = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
	}

	void Camera::Update()
	{
		if (Input::GetKeyHold(eKeyCode::A))
			mLookPosition.x -= 100.0f * Time::DeltaTime();

		if (Input::GetKeyHold(eKeyCode::D))
			mLookPosition.x += 100.0f * Time::DeltaTime();

		if (Input::GetKeyHold(eKeyCode::W))
			mLookPosition.y -= 100.0f * Time::DeltaTime();

		if (Input::GetKeyHold(eKeyCode::S))
			mLookPosition.y += 100.0f * Time::DeltaTime();


		if (mTarget != nullptr)
		{
			mLookPosition
				= mTarget->GetComponent<Transform>()->GetPos();
		}

		mDistance = mLookPosition - (mResolution / 2.0f);
	}

	void Camera::Clear()
	{
		mResolution.x = application.GetWidth();
		mResolution.x = application.GetHeight();
		mLookPosition = (mResolution / 2.0f);
		mDistance = Vector2::Zero;
	}

}