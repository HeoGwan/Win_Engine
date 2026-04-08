#pragma once
#include "idhComponent.h"
#include "idhGameObject.h"
#include "idhLayer.h"
#include "idhScene.h"
#include "idhSceneManager.h"
#include "idhTransform.h"

namespace idh::object
{
	template <typename T>
	static T* Instantiate(idh::enums::eLayerType type)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(idh::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* obj)
	{
		obj->Death();
	}
}