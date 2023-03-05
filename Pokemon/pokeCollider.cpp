#include "pokeCollider.h"
#include "pokeTransform.h"
#include "pokeGameObject.h"

namespace poke
{
	Collider::Collider()
		: Component(eComponentType::Collider)
		, mCenter(Vector2::Zero)
		, mScale(Vector2::One)
		, mPos(Vector2::Zero)
		, mSize(60.0f, 80.f)
	{

	}

	Collider::~Collider()
	{

	}

	void Collider::Initialize()
	{

	}

	void Collider::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		mPos = tr->GetPos() + mCenter;
	}

	void Collider::Render(HDC hdc)
	{
		HPEN pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Rectangle(hdc, mPos.x, mPos.y, mPos.x - mSize.x, mPos.y + mSize.y);

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(pen);
	}

	void Collider::Release()
	{

	}
}