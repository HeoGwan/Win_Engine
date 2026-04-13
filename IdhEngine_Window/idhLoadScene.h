#pragma once
#include "..\\IdhEngine_SOURCE\\idhSceneManager.h"

#include "idhPlayScene.h"
#include "idhTitleScene.h"
#include "idhToolScene.h"

namespace idh
{
	void LoadScenes()
	{
		//SceneManager::CreateScene<TitleScene>(L"TitleScene");
		//SceneManager::CreateScene<PlayScene>(L"PlayScene");
		//SceneManager::CreateScene<EndScene>(L"EndScene");

		SceneManager::CreateScene<ToolScene>(L"ToolScene");

		SceneManager::LoadScene(L"ToolScene");
	}
}