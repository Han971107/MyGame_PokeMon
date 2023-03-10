#include "pokeImage.h"
#include "pokeApplication.h"
#include "pokeResourceManager.h"

extern poke::Application application;

namespace poke
{
	Image* Image::CreateEmptySpriteSheet(const std::wstring& name, UINT width, UINT height)
	{
		if (width == 0 || height == 0)
			return nullptr;

		Image* image = ResourceManager::Find<Image>(name);
		if (image != nullptr)
			return image;

		image = new Image();
		HDC mainHdc = application.GetHdc();

		image->mBitmap = CreateCompatibleBitmap(mainHdc, width, height);
		image->mHdc = CreateCompatibleDC(mainHdc);

		HBITMAP oldBitmap =  (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		image->mWidth = width;
		image->mHeight = height;

		image->SetKey(name);
		ResourceManager::Insert<Image>(name, image);

		Rectangle(image->GetHdc(), -1, -1, image->mWidth + 1, image->mHeight + 1);
		
		return image;
	}

	Image* Image::CreateTexture(const std::wstring& name, UINT width, UINT height)
	{
		if (width == 0 || height == 0)
			return nullptr;

		Image* image = ResourceManager::Find<Image>(name);
		if (image != nullptr)
			return image;

		image = new Image();
		image->mWidth = width;
		image->mHeight = height;

		HDC mainHdc = application.GetHdc();

		//------------------------------------------------------------------
		// 원본 백버퍼와, 비트맵 정보를 가져온다
		image->mBitmap = application.GetBackBuffer();
		image->mHdc = application.GetBackHdc();
		image->mBitmap = CreateCompatibleBitmap(mainHdc, width, height);
		image->mHdc = CreateCompatibleDC(mainHdc);
		//------------------------------------------------------------------

		HBITMAP oldBitmap = (HBITMAP)SelectObject(image->mHdc, image->mBitmap);
		DeleteObject(oldBitmap);

		image->SetKey(name);
		ResourceManager::Insert<Image>(name, image);

		Rectangle(image->GetHdc(), -1, -1, image->mWidth + 1, image->mHeight + 1);

		return image;
	}

	Image::Image()
		: mBitmap(NULL)
		, mHdc(NULL)
		, mWidth(0)
		, mHeight(0)
	{

	}

	Image::~Image()
	{

	}

	HRESULT Image::Load(const std::wstring& path)
	{
		mBitmap = (HBITMAP)LoadImage(nullptr
			, path.c_str(), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE | LR_CREATEDIBSECTION);

		if (mBitmap == nullptr)
			return E_FAIL;

		BITMAP bitInfo = {};
		GetObject(mBitmap, sizeof(BITMAP), &bitInfo);

		mWidth = bitInfo.bmWidth;
		mHeight = bitInfo.bmHeight;

		HDC mainDC = application.GetHdc();
		mHdc = CreateCompatibleDC(mainDC);

		HBITMAP oldBitmap = (HBITMAP)SelectObject(mHdc, mBitmap);
		DeleteObject(oldBitmap);

		return S_OK;
	}
}