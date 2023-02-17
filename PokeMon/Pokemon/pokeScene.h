#pragma once
#include "pokeEntity.h"
#include "pokeLayer.h"


namespace poke
{
	class Scene : public Entity
	{
	public:

		Scene();
		virtual ~Scene();

		virtual void Initialize();
		virtual void Update();
		virtual void Render(HDC hdc);
		virtual void Release();

		void AddGameObject(GameObject* obj, eLayerType layer);

	private:
		std::vector<Layer> mLayers;
	};
}

