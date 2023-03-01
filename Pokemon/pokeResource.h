#pragma once
#include "pokeEntity.h"

namespace poke
{
	class Resource
	{	
	public:
		Resource();
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0;

		const std::wstring& GetKey() { return mKey; }
		const std::wstring& GetPath() { return mPath; }
		void SetKey(const std::wstring& key) { mKey = key; }
		void SetPath(const std::wstring& path) { mKey = path; }

	private:
		std::wstring mKey;
		std::wstring mPath;
	};
}