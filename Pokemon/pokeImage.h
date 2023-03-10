#pragma once
#include "pokeResource.h"

namespace poke
{
    class Image : public Resource
    {
	public:	
		static Image* CreateEmptySpriteSheet(const std::wstring& name, UINT width, UINT height);
		static Image* CreateTexture(const std::wstring& name, UINT width, UINT height);

		Image();
		virtual ~Image();

		virtual HRESULT Load(const std::wstring& path) override;

		HDC GetHdc() { return mHdc; }
		HBITMAP GetBitmap() { return mBitmap; }
		UINT GetWidth() { return mWidth; }
		UINT GetHeight() { return mHeight; }

	private:
		HBITMAP mBitmap;
		HDC mHdc;
		UINT mWidth;
		UINT mHeight;
    };
}

