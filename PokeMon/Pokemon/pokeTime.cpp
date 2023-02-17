#include "pokeTime.h"


namespace poke
{
	double Time::mDeltaTime = 0.0l;
	LARGE_INTEGER Time::mCpuFrequency{};
	LARGE_INTEGER Time::mPrevFrequency{};
	LARGE_INTEGER Time::mCurrFrequency{};
	double Time::mSecond = 0.0l;

	void Time::Initialize()
	{
		// CPU 고유 진동수 가져오기
		QueryPerformanceFrequency(&mCpuFrequency);

		// 프로그램 처음 시작할 때 진동수
		QueryPerformanceCounter(&mPrevFrequency);
	}

	void Time::Update()
	{
		QueryPerformanceCounter(&mCurrFrequency);

		double differenceFrequency = mCurrFrequency.QuadPart - mPrevFrequency.QuadPart;

		mDeltaTime = differenceFrequency / mCpuFrequency.QuadPart;
		mPrevFrequency.QuadPart = mCurrFrequency.QuadPart;
	}

	void Time::Render(HDC hdc)
	{
		mSecond += DeltaTime();

		if (mSecond > 1.0f)
		{
			HWND hwnd = pokeApplication.GetHwnd();

			wchar_t szFloat[50]{};
			float FPS = 1.0f / mDeltaTime;
			swprintf_s(szFloat, 50, L"FPS : %d", (UINT)FPS);
			int iLen = wcsnlen_s(szFloat, 50);

			SetWindowText(hwnd, szFloat);

			mSecond = 0.0f;
		}
	}
}