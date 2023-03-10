#pragma once
#include "pokeGameObject.h"
#include "pokeScene.h"
#include "pokeSceneManager.h"
#include "pokeTransform.h"


namespace poke::Object
{
	template <typename T>
	static inline T* Instantiate(eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		return gameObj;
	}

	template <typename T>
	static inline T* Instantiate(Vector2 pos, eLayerType type)
	{
		T* gameObj = new T();
		Scene* scene = SceneManager::GetActiveScene();
		scene->AddGameObject(gameObj, type);
		gameObj->Initialize();
		gameObj->GameObject::GetComponent<Transform>()->SetPos(pos);

		return gameObj;
	}


	static void Destroy(GameObject* obj)
	{
		obj->SetState(GameObject::eState::Death);
	}
}