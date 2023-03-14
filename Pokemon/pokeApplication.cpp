#include "pokeApplication.h"
#include "pokeSceneManager.h"
#include "pokeTime.h"
#include "pokeInput.h"
#include "pokeCollisionManager.h"
#include "pokeCamera.h"
#include "pokeImage.h"


namespace poke
{
	Application::Application()
		: mHwnd(NULL)
		, mHdc(NULL)
		, mImage(nullptr)
		, mBackBuffer(NULL)
		, mBackHDC(NULL)
		, mWidth(0)
		, mHeight(0)
		, mPos(Vector2::One)
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

		mImage = Image::CreateTexture(L"BackBuffer", mWidth, mHeight);

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

		Time::Render(mImage->GetHdc());
		Input::Render(mImage->GetHdc());
		SceneManager::Render(mImage->GetHdc());

		// Camera effect�� true�� ���, ��� ���� �׸��� �������ش�
		Camera::Render(mImage->GetHdc());

		// ����ۿ� �ִ� �׸��� �������ۿ� �׷�����Ѵ�.
		BitBlt(mHdc, 0, 0, mWidth, mHeight, mImage->GetHdc(), 0, 0, SRCCOPY);
	}

	void Application::clear()
	{
		//HBRUSH grayBrush = CreateSolidBrush(RGB(121, 121, 121));
		HBRUSH blackBrush = CreateSolidBrush(RGB(0, 0, 0));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mImage->GetHdc(), blackBrush);
		Rectangle(mImage->GetHdc(), -1, -1, mWidth + 1, mHeight + 1);
		SelectObject(mImage->GetHdc(), oldBrush);
		DeleteObject(blackBrush);
	}
}