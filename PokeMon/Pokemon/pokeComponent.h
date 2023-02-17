#pragma once
#include "pokeEntity.h"

namespace poke
{
	class Component : public Entity
	{
	public:

		Component();
		~Component();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

	private:

	};
}
