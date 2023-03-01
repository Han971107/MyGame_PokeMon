#pragma once
#include "pokeEntity.h"

namespace poke
{
	class GameObject;

	class Component : public Entity
	{
	public:
		Component();
		Component(eComponentType type);
		virtual ~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		eComponentType GetType() { return mType; }
		void SetOwner(GameObject* owner) { mOwner = owner; }
		GameObject* GetOwner() { return mOwner; }

	private:
		eComponentType mType;
		GameObject* mOwner;
	};
}

