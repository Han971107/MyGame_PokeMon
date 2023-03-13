#include "pokeBackGround.h"
#include "pokeImage.h"
#include "pokeTransform.h"
#include "pokeAnimator.h"


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
		GameObject::Initialize();
	}

	void BackGround::Update()
	{
		GameObject::Update();
	}

	void BackGround::Render(HDC hdc)
	{
		Transform* tr = GetComponent<Transform>();
		Vector2 pos = tr->GetPos();
		Vector2 scale = tr->GetScale();

		BitBlt(hdc, pos.x, pos.y, mImage->GetWidth() * scale.x, mImage->GetHeight() * scale.y, mImage->GetHdc(), 0, 0, SRCCOPY);

		// comp render는 순서상 마지막에 그려야한다.
		GameObject::Render(hdc);
	}

	void BackGround::Release()
	{
		GameObject::Release();
	}

	void BackGround::SetImage(const std::wstring& key, const std::wstring& path)
	{
		mImage = ResourceManager::Load<Image>(key, path);
	}

}