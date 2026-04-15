#include "idhPlayScene.h"
#include "idhGameObject.h"
#include "idhPlayer.h"
#include "idhTransform.h"
#include "idhSpriteRenderer.h"
#include "idhInput.h"
#include "idhSceneManager.h"
#include "idhObject.h"
#include "idhTexture.h"
#include "idhResources.h"
#include "idhPlayerScript.h"
#include "idhCamera.h"
#include "idhRenderer.h"
#include "idhAnimator.h"
#include "idhCat.h"
#include "idhCatScript.h"
#include "idhBoxCollider2D.h"
#include "idhCircleCollider2D.h"
#include "idhCollisionManager.h"
#include "idhTile.h"
#include "idhTilemapRenderer.h"
#include "idhRigidbody.h"
#include "idhFloor.h"
#include "idhFloorScript.h"
#include "idhUIManager.h"
#include "idhAudioClip.h"
#include "idhAudioListener.h"
#include "idhAudioSource.h"


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
		// main camera
		GameObject* camera = object::Instantiate<GameObject>(enums::eLayerType::Particle, Vector2(344.0f, 442.0f));
		Camera* cameraComp = camera->AddComponent<Camera>();
		renderer::mainCamera = cameraComp;


		mPlayer = object::Instantiate<Player>(enums::eLayerType::Player);
		object::DontDestroyOnLoad(mPlayer);
		mPlayer->AddComponent<AudioListener>();

		PlayerScript* plScript = mPlayer->AddComponent<PlayerScript>();

		BoxCollider2D* collider = mPlayer->AddComponent<BoxCollider2D>();
		collider->SetOffset(Vector2(-50.0f, -50.0f));

		graphics::Texture* playerTex = Resources::Find<graphics::Texture>(L"Player");
		Animator* playerAnimator = mPlayer->AddComponent<Animator>();
		playerAnimator->CreateAnimation(L"Idle", playerTex
			, Vector2(2000.0f, 250.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 1, 0.1f);
		playerAnimator->CreateAnimation(L"FrontGiveWater", playerTex
			, Vector2(0.0f, 2000.0f), Vector2(250.0f, 250.0f), Vector2::Zero, 12, 0.1f);
		playerAnimator->PlayAnimation(L"Idle", false);

		playerAnimator->GetCompleteEvent(L"FrontGiveWater") = std::bind(&PlayerScript::AttackEffect, plScript);

		mPlayer->GetComponent<Transform>()->SetPosition(Vector2(300.0f, 250.0f));
		mPlayer->AddComponent<Rigidbody>();



		Floor* floor = object::Instantiate<Floor>(eLayerType::Floor, Vector2(0.0f, 0.0f));
		floor->SetName(L"Floor");
		SpriteRenderer* floorSR = floor->AddComponent<SpriteRenderer>();
		floorSR->SetTexture(Resources::Find<graphics::Texture>(L"PixelMap"));

		AudioSource* as = floor->AddComponent<AudioSource>();

		plScript->SetPixelMapTexture(Resources::Find<graphics::Texture>(L"PixelMap"));

		//BoxCollider2D* floorCol = floor->AddComponent<BoxCollider2D>();
		//floorCol->SetSize(Vector2(3.0f, 1.0f));
		//floor->AddComponent<FloorScript>();
		
		AudioClip* ac = Resources::Load<AudioClip>(L"BGSound", L"..\\Resources\\Sound\\smw_bonus_game_end.wav");
		as->SetClip(ac);
		//as->Play();

		// 게임 오브젝트 생성후에 레이어와 게임오브젝트들의 init함수를 호출
		Scene::Initialize();
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
		//wchar_t str[50] = L"Play Scene";
		//TextOut(hdc, 0, 0, str, 10);
	}

	void PlayScene::OnEnter()
	{
		Scene::OnEnter();

		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Animal, true);
		CollisionManager::CollisionLayerCheck(eLayerType::Player, eLayerType::Floor, true);

		UIManager::Push(eUIType::Button);
	}

	void PlayScene::OnExit()
	{
		UIManager::Pop(eUIType::Button);

		Scene::OnExit();
	}
}