#include "pokeRed.h"


namespace poke
{
	Red::Red()
	{

	}

	Red::~Red()
	{

	}

	void Red::Initialize()
	{
		GameObject::Initialize();
	}

	void Red::Update()
	{
		GameObject::Update();

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

	void Red::Render(HDC hdc)
	{
		GameObject::Render(hdc);
		// stock 오브젝트
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);
		//Rectangle(mHdc, -1, -1, 1601, 901);

		HPEN pen = CreatePen(PS_SOLID, 2, RGB(255, 0, 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);

		Rectangle(hdc, mPos.x, mPos.y, mPos.x + 100, mPos.y + 100);

		SelectObject(hdc, oldPen);
		DeleteObject(pen);
		SelectObject(hdc, oldBrush);
		DeleteObject(brush);
	}

	void Red::Release()
	{
		GameObject::Release();
	}
}
