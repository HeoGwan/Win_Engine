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
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		return gameObject;
	}

	template <typename T>
	static T* Instantiate(idh::enums::eLayerType type, math::Vector2 position)
	{
		T* gameObject = new T();
		gameObject->SetLayerType(type);
		Scene* activeScene = SceneManager::GetActiveScene();
		Layer* layer = activeScene->GetLayer(type);
		layer->AddGameObject(gameObject);

		Transform* tr = gameObject->GetComponent<Transform>();
		tr->SetPosition(position);

		return gameObject;
	}

	static void Destroy(GameObject* gameObject)
	{
		if (gameObject == nullptr)
			return;

		gameObject->Death();
	}

	static void DontDestroyOnLoad(GameObject* gameObject)
	{
		Scene* activeScene = SceneManager::GetActiveScene();
		// 현재 씬에서 게임 오브젝트를 지워준다.
		activeScene->EraseGameObject(gameObject);

		// 해당 게임 오브젝트를 -> DontDestroy씬으로 넣어준다.
		Scene* dontDestroyOnLoad = SceneManager::GetDontDestroyScene();
		dontDestroyOnLoad->AddGameObject(gameObject, gameObject->GetLayerType());
	}
}