#include "pokeCollider.h"
#include "pokeTransform.h"
#include "pokeGameObject.h"
#include "pokeCamera.h"


namespace poke
{
	UINT Collider::ColliderNumber = 0;

	Collider::Collider()
		: Component(eComponentType::Collider)
		, mCenter(Vector2::Zero)	
		, mPos(Vector2::Zero)
		, mSize(Vector2::One)
		, mID(ColliderNumber++)
		, mCollisionCount(0)
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
		HPEN pen = NULL;
		if (mCollisionCount <= 0)
		{
			pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
		}
		else
		{
			pen = CreatePen(BS_SOLID, 2, RGB(255, 0, 0));
		}

		//HPEN pen = CreatePen(BS_SOLID, 2, RGB(0, 255, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, pen);
		HBRUSH brush = (HBRUSH)GetStockObject(NULL_BRUSH);
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, brush);

		Vector2 pos = Camera::CalculatePos(mPos);
		Rectangle(hdc, pos.x, pos.y, pos.x + mSize.x, pos.y + mSize.y);

		(HPEN)SelectObject(hdc, oldPen);
		DeleteObject(pen);
	}

	void Collider::Release()
	{

	}

	void Collider::OnCollisionEnter(Collider* other)
	{
		GetOwner()->OnCollisionEnter(other);
	}

	void Collider::OnCollisionStay(Collider* other)
	{
		GetOwner()->OnCollisionStay(other);
	}

	void Collider::OnCollisionExit(Collider* other)
	{
		GetOwner()->OnCollisionExit(other);
	}
}