#include "pokeApplication.h"
#include "pokeSceneManager.h"
#include "pokeTime.h"
#include "pokeInput.h"


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
		mWidth = 1920;
		mHeight = 1080;

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
	}

	void Application::Run()
	{
		Update();
		Render();
	}

	void Application::Update()
	{
		Time::Update();
		Input::Update();
		SceneManager::Update();
	}

	void poke::Application::Render()
	{
		// clear
		Rectangle(mBackHDC, -1, -1, 1921, 1081);

		Time::Render(mBackHDC);
		Input::Render(mBackHDC);
		SceneManager::Render(mBackHDC);

		// ����ۿ� �ִ� �׸��� �������ۿ� �׷�����Ѵ�.
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mBackHDC, 0, 0, SRCCOPY);
	}
}