#include "pokeApplication.h"


namespace poke
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
	{

	}

	Application::~Application()
	{

	}

	void Application::Initialize(HWND hWnd)
	{
		mHwnd = hWnd;
		mHdc = GetDC(hWnd);
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		if (GetAsyncKeyState(VK_LEFT) & 0x8000)
		{
			mPos.x -= 0.01f;
		}

		if (GetAsyncKeyState(VK_RIGHT) & 0x8000)
		{
			mPos.x += 0.01f;
		}

		if (GetAsyncKeyState(VK_UP) & 0x8000)
		{
			mPos.y -= 0.01f;
		}

		if (GetAsyncKeyState(VK_DOWN) & 0x8000)
		{
			mPos.y += 0.01f;
		}
	}

	void Application::Render()
	{
		// stock 오브젝트
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);
		//Rectangle(mHdc, -1, -1, 1601, 901);

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(mHdc, pen);

		Rectangle(mHdc, mPos.x, mPos.y, mPos.x + 100, mPos.y + 100);

		SelectObject(mHdc, oldPen);
		DeleteObject(pen);
		SelectObject(mHdc, oldBrush);
		DeleteObject(brush);
	}
}