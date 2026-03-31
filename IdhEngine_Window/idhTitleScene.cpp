#include "idhTitleScene.h"
#include "idhInput.h"
#include "idhSceneManager.h"
#include "idhGameObject.h"
#include "idhObject.h"
#include "idhSpriteRenderer.h"

namespace idh
{
	TitleScene::TitleScene()
	{
	}

	TitleScene::~TitleScene()
	{
	}

	void TitleScene::Initialize()
	{
		Scene::Initialize();
		/*{
			bg = object::Instantiate<GameObject>
				(enums::eLayerType::BackGround);
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"C:\\Users\\DSU\\Desktop\\04_Study\\02_C++\\Editor_Window\\IdhEngine\\Resources\\CloudOcean.png");

			bg = object::Instantiate<GameObject>
				(enums::eLayerType::Player, Vector2(500.0f, 100.0f));
			sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"C:\\Users\\DSU\\Desktop\\04_Study\\02_C++\\Editor_Window\\IdhEngine\\Resources\\DungreedTitle.png");
		}*/
	}

	void TitleScene::Update()
	{
		Scene::Update();
	}

	void TitleScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"PlayScene");
		}
	}

	void TitleScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Title Scene";
		TextOut(hdc, 0, 0, str, 11);
	}
}