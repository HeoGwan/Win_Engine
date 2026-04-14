#include "idhSceneManager.h"
#include "idhDontDestroyOnLoad.h"

namespace idh
{
	std::map<std::wstring, Scene*> SceneManager::mScene = {};
	Scene* SceneManager::mActiveScene = nullptr;
	Scene* SceneManager::mDontDestroyScene = nullptr;

	Scene* SceneManager::LoadScene(const std::wstring& name)
	{
		if (mActiveScene)
			mActiveScene->OnExit();

		std::map<std::wstring, Scene*>::iterator iter
			= mScene.find(name);

		if (iter == mScene.end())
			return nullptr;

		mActiveScene = iter->second;
		mActiveScene->OnEnter();

		return iter->second;
	}

	std::vector<GameObject*> SceneManager::GetGameObjects(eLayerType layer)
	{
		std::vector<GameObject*> gameObjects
			= mActiveScene->GetLayer(layer)->GetGameObjects();
		std::vector<GameObject*> dontDestroyOnLoad 
			= mDontDestroyScene->GetLayer(layer)->GetGameObjects();

		gameObjects.insert(gameObjects.end()
			, dontDestroyOnLoad.begin(), dontDestroyOnLoad.end());

		return gameObjects;
	}

	void SceneManager::Initialize()
	{
		mDontDestroyScene = CreateScene<DontDestroyOnLoad>(L"DontDestroyOnLoad");
	}
	
	void SceneManager::Update()
	{
		mActiveScene->Update();
		mDontDestroyScene->Update();
	}
	
	void SceneManager::LateUpdate()
	{
		mActiveScene->LateUpdate();
		mDontDestroyScene->LateUpdate();
	}
	
	void SceneManager::Render(HDC hdc)
	{
		mActiveScene->Render(hdc);
		mDontDestroyScene->Render(hdc);
	}

	void SceneManager::Destroy()
	{
		mActiveScene->Destroy();
		mDontDestroyScene->Destroy();
	}

	void SceneManager::Release()
	{
		for (auto& iter : mScene)
		{
			delete iter.second;
			iter.second = nullptr;
		}
	}
}