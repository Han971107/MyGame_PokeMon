#pragma once
#include "pokeEntity.h"

namespace poke
{
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

	private:
		eComponentType mType;
	};
}

