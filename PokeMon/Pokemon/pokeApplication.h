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

	private:
		HWND mHwnd;
		HDC mHdc;

		Vector2 mPos;
	};
}

