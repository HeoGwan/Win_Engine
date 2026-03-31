#include "idhPlayScene.h"
#include "idhGameObject.h"
#include "idhPlayer.h"
#include "idhTransform.h"
#include "idhSpriteRenderer.h"
#include "idhInput.h"
#include "idhSceneManager.h"
#include "idhObject.h"

namespace idh
{
	PlayScene::PlayScene()
	{
	
	}
	
	PlayScene::~PlayScene()
	{
	
	}
	
	void PlayScene::Initialize()
	{
		{
			//bg = new Player();
			//Transform* tr
			//	= bg->AddComponent<Transform>();
			//tr->SetPosition(Vector2(0, 0));

			//tr->SetName(L"TR");

			//SpriteRenderer* sr
			//	= bg->AddComponent<SpriteRenderer>();
			//sr->SetName(L"SR");
			//sr->ImageLoad(L"C:\\Users\\DSU\\Desktop\\04_Study\\02_C++\\Editor_Window\\IdhEngine\\Resources\\CloudOcean.png");

			//AddGameObject(bg, eLayerType::BackGround);

			bg = object::Instantiate<Player>
				(enums::eLayerType::BackGround, Vector2(100.0f, 100.0f));
			SpriteRenderer* sr = bg->AddComponent<SpriteRenderer>();
			sr->ImageLoad(L"C:\\Users\\DSU\\Desktop\\04_Study\\02_C++\\Editor_Window\\IdhEngine\\Resources\\CloudOcean.png");
		}
	}
	
	void PlayScene::Update()
	{
		Scene::Update();
	}
	
	void PlayScene::LateUpdate()
	{
		Scene::LateUpdate();
		if (Input::GetKeyDown(eKeyCode::N))
		{
			SceneManager::LoadScene(L"TitleScene");
		}
	}

	void PlayScene::Render(HDC hdc)
	{
		Scene::Render(hdc);
		wchar_t str[50] = L"Play Scene";
		TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{

	}

	void PlayScene::OnExit()
	{
		//Transform* tr = bg->GetComponent<Transform>();
		//tr->SetPosition(Vector2(0, 0));
	}
}