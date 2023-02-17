#pragma once
#include "MergeEngine.h"


namespace poke
{
	class Application
	{
	public:
		Application();
		~Application();

		void Initialize(HWND hWnd);
		void Run();
		void Update();
		void Render();

		HWND GetHwnd() { return mHwnd; }

	private:
		HWND mHwnd;
		HDC mHdc;

		Vector2 mPos;
	};
}