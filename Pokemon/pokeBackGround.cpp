#include "pokeBackGround.h"
#include "pokeImage.h"
#include "pokeTransform.h"
#include "pokeAnimator.h"
#include "pokeCamera.h"
#include "pokeHomeScene.h"
#include "pokeSceneManager.h"


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
		if (mImage->GetKey() == L"..\\Resources\\HomeScene.bmp")
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			Vector2 scale = tr->GetScale();

			pos = Camera::CalculatePos(pos);

			BitBlt(hdc, pos.x, pos.y, mImage->GetWidth() * scale.x, mImage->GetHeight() * scale.y, mImage->GetHdc(), 0, 0, SRCCOPY);
		}
		else
		{
			Transform* tr = GetComponent<Transform>();
			Vector2 pos = tr->GetPos();
			Vector2 scale = tr->GetScale();

			BitBlt(hdc, pos.x, pos.y, mImage->GetWidth() * scale.x, mImage->GetHeight() * scale.y, mImage->GetHdc(), 0, 0, SRCCOPY);	// stretchblt 함수로 수정할 것
		}

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