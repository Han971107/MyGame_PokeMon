#pragma once
#include "CommonInclude.h"
#include "pokeApplication.h"

extern poke::Application pokeApplication;

namespace poke
{
	class Time
	{
	public:

		static void Initialize();
		static void Update();
		static void Render(HDC hdc);

		static double DeltaTime() { return mDeltaTime; }

	private:
		static double mDeltaTime;
		static LARGE_INTEGER mCpuFrequency;
		static LARGE_INTEGER mPrevFrequency;
		static LARGE_INTEGER mCurrFrequency;

	private:
		static double mSecond;
	};
}

