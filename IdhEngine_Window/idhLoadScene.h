#pragma once
#include "..\\IdhEngine_SOURCE\\idhSceneManager.h"

#include "idhPlayScene.h"

namespace idh
{
	void LoadScenes()
	{
		SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");

		SceneManager::LoadScene(L"PlayScene");
	}
}