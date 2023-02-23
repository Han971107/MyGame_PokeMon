#pragma once
#include "pokeResource.h"

namespace poke
{
    class Image : public Resource
    {
    public:
        Image();
        ~Image();

        virtual HRESULT Load(const std::wstring& path) override;

        HDC GetHdc() { return mHdc; }
        HBITMAP GetBitmap() { return mBitmap; }
        const UINT GetWidth() { return mWidth; }
        const UINT GetHeight() { return mHeight; }

    private:
        HBITMAP mBitmap;
        HDC mHdc;
        UINT mWidth;
        UINT mHeight;
    };
}

