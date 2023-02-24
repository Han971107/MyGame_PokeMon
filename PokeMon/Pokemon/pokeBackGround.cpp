#include "pokeBackGround.h"
#include "pokeImage.h"
#include "pokeTransform.h"

namespace poke
{
	BackGround::BackGround()
	{

	}

	BackGround::~BackGround()
	{

	}

	void BackGround::Initialize()
	{
		
	}

	void BackGround::Update()
	{

	}

	void BackGround::Render(HDC hdc)
	{
		GameObject::Render(hdc);

		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth(), mImage->GetHeight(), mImage->GetHdc(), 0, 0, SRCCOPY);
	}

	void BackGround::Release()
	{

	}

	void BackGround::SetImage(const std::wstring& key, const std::wstring& path)
	{
		mImage = ResourceManager::Load<Image>(key, path);
	}

}