#include "pokeApplication.h"
#include "pokeSceneManager.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeCollisionManager.h"
#include "pokeCamera.h"


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
		mWidth = 800;
		mHeight = 660;
		//mWidth = 1490;
		//mHeight = 990;

		// ��Ʈ�� �ػ󵵸� �����ϱ� ���� ���� ������ ũ�⸦ ������ش�/
		RECT rect = { 0, 0, mWidth, mHeight };
		AdjustWindowRect(&rect, WS_EX_OVERLAPPEDWINDOW, false);

		// ������ ũ�� ���� �� ��� ����
		SetWindowPos(mHwnd
			, nullptr, 100, 50
			, rect.right - rect.left
			, rect.bottom - rect.top
			, 0);
		ShowWindow(hWnd, true);

		mBackBuffer = CreateCompatibleBitmap(mHdc, mWidth, mHeight);
		mBackHDC = CreateCompatibleDC(mHdc);
		HBITMAP defaultBitmap = (HBITMAP)SelectObject(mBackHDC, mBackBuffer);
		DeleteObject(defaultBitmap);

		Time::Initialize();
		Input::Initialize();
		SceneManager::Initialize();
		Camera::Initialize();
	}

	void Application::Run()
	{
		Update();
		Render();
		SceneManager::Destroy();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		Camera::Update();

		SceneManager::Update();
		CollisionManager::Update();
	}

	void poke::Application::Render()
	{
		// clear
		clear();

		Time::Render(mBackHDC);
		Input::Render(mBackHDC);
		SceneManager::Render(mBackHDC);

		// ����ۿ� �ִ� �׸��� �������ۿ� �׷�����Ѵ�.
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}

	void Application::clear()
	{
		//HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
		HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mBackHDC, blackBrush);
		Rectangle(mBackHDC, -1, -1, mWidth + 1, mHeight + 1);
		SelectObject(mBackHDC, oldBrush);
		DeleteObject(blackBrush);
	}
}