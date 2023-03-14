#pragma once
#include "MergeEngine.h"


namespace poke
{
	class Image;

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
		HDC GetHdc() { return mHdc; }

		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

		HBITMAP GetBackBuffer() { return mBackBuffer; }
		HDC GetBackHdc() { return mBackHDC; }

	private:
		void clear();

	private:
		HWND mHwnd;
		HDC mHdc;

		//¹é¹öÆÛ
		Image* mImage;

		HBITMAP mBackBuffer;
		HDC mBackHDC;

		UINT mWidth;
		UINT mHeight;
		Vector2 mPos;
	};
}