#include "idhPlayerScript.h"
#include "idhInput.h"
#include "idhTransform.h"
#include "idhTime.h"
#include "idhGameObject.h"
#include "idhAnimator.h"
#include "idhCat.h"
#include "idhCatScript.h"
#include "idhObject.h"
#include "idhResources.h"
#include "idhCollider.h"
#include "idhRigidbody.h"
#include "idhUIManager.h"

namespace idh
{
	PlayerScript::PlayerScript()
		: mState(PlayerScript::eState::Idle)
		, mAnimator(nullptr)
	{
	
	}
	
	PlayerScript::~PlayerScript()
	{
	
	}

	void PlayerScript::Initialize()
	{
		
	}
	
	void PlayerScript::Update()
	{
		if (mAnimator == nullptr)
			mAnimator = GetOwner()->GetComponent<Animator>();
				
		switch (mState)
		{
		case idh::PlayerScript::eState::Idle:
			idle();
			break;
		case idh::PlayerScript::eState::Walk:
			move();
			break;
		case idh::PlayerScript::eState::Sleep:
			break;
		case idh::PlayerScript::eState::GiveWater:
			giveWater();
			break;
		case idh::PlayerScript::eState::Attack:
			break;
		default:
			break;
		}

		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();
		COLORREF color = mPixelMap->GetPixel(pos.x, pos.y + 50);

		Rigidbody* playerRb = GetOwner()->GetComponent<Rigidbody>();
		if (color == RGB(255, 0, 0))
		{
			playerRb->SetGround(true);

			pos.y -= 1;
			tr->SetPosition(pos);
		}
		else
		{
			playerRb->SetGround(false);
		}
	}
	
	void PlayerScript::LateUpdate()
	{
	
	}

	void PlayerScript::Render(HDC hdc)
	{

	}

	void PlayerScript::AttackEffect()
	{
		Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
		CatScript* catSrc = cat->AddComponent<CatScript>();
		catSrc->SetPlayer(GetOwner());

		graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
		Animator* catAnimator = cat->AddComponent<Animator>();
		catAnimator->CreateAnimation(L"DownWalk", catTexture
			, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"RightWalk", catTexture
			, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"UpWalk", catTexture
			, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LeftWalk", catTexture
			, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"SitDown", catTexture
			, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"Grooming", catTexture
			, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
		catAnimator->CreateAnimation(L"LayDown", catTexture
			, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

		Transform* tr = GetOwner()->GetComponent<Transform>();

		catAnimator->PlayAnimation(L"SitDown", false);
		cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
		cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

		Vector2 mousePos = Input::GetMousePosition();
		catSrc->mDest = mousePos;
	}

	void PlayerScript::OnCollisionEnter(class Collider* other)
	{
		//other->GetOwner()->GetComponent<Transform>()->SetPosition(Vector2(400.0f, 500.0f));
	}

	void PlayerScript::OnCollisionStay(class Collider* other)
	{
		
	}

	void PlayerScript::OnCollisionExit(class Collider* other)
	{
		
	}

	void PlayerScript::idle()
	{
		if (Input::GetKey(eKeyCode::LButton))
		{
			Cat* cat = object::Instantiate<Cat>(enums::eLayerType::Animal);
			CatScript* catSrc = cat->AddComponent<CatScript>();
			catSrc->SetPlayer(GetOwner());

			graphics::Texture* catTexture = Resources::Find<graphics::Texture>(L"Cat");
			Animator* catAnimator = cat->AddComponent<Animator>();
			catAnimator->CreateAnimation(L"DownWalk", catTexture
				, Vector2(0.0f, 0.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"RightWalk", catTexture
				, Vector2(0.0f, 32.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"UpWalk", catTexture
				, Vector2(0.0f, 64.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LeftWalk", catTexture
				, Vector2(0.0f, 96.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"SitDown", catTexture
				, Vector2(0.0f, 128.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"Grooming", catTexture
				, Vector2(0.0f, 160.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);
			catAnimator->CreateAnimation(L"LayDown", catTexture
				, Vector2(0.0f, 192.0f), Vector2(32.0f, 32.0f), Vector2::Zero, 4, 0.1f);

			Transform* tr = GetOwner()->GetComponent<Transform>();

			catAnimator->PlayAnimation(L"SitDown", false);
			cat->GetComponent<Transform>()->SetPosition(tr->GetPosition());
			cat->GetComponent<Transform>()->SetScale(Vector2(2.0f, 2.0f));

			Vector2 mousePos = Input::GetMousePosition();
			catSrc->mDest = mousePos;

			//mState = PlayerScript::eState::GiveWater;
			//mAnimator->PlayAnimation(L"FrontGiveWater", false);

			//Vector2 mousePos = Input::GetMousePosition();
			//int a = 0;
		}
	
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if (Input::GetKey(eKeyCode::D))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::A))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(-200.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::W))
		{
			//pos.y -= 100.0f * Time::DeltaTime();
			//rb->AddForce(Vector2(0.0f, -200.0f));
			Vector2 velocity = rb->GetVelocity();
			velocity.y = -500.0f;
			rb->SetVelocity(velocity);
			rb->SetGround(false);
		}

		if (Input::GetKeyDown(eKeyCode::I))
		{
			UIManager::Push(eUIType::HpBar);
		}

		if (Input::GetKeyDown(eKeyCode::O))
		{
			UIManager::Pop(eUIType::HpBar);
		}
	}

	void PlayerScript::move()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		Rigidbody* rb = GetOwner()->GetComponent<Rigidbody>();

		if (Input::GetKey(eKeyCode::D))
		{
			//pos.x += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(400.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::A))
		{
			//pos.x -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(-400.0f, 0.0f));
		}
		if (Input::GetKey(eKeyCode::W))
		{
			//pos.y -= 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(0.0f, -200.0f));
		}
		if (Input::GetKey(eKeyCode::S))
		{
			//pos.y += 100.0f * Time::DeltaTime();
			rb->AddForce(Vector2(0.0f, 200.0f));
		}

		//tr->SetPosition(pos);

		if (Input::GetKeyUp(eKeyCode::D) || Input::GetKeyUp(eKeyCode::A)
			|| Input::GetKeyUp(eKeyCode::W) || Input::GetKeyUp(eKeyCode::S))
		{
			mState = PlayerScript::eState::Idle;
			mAnimator->PlayAnimation(L"SitDown", false);
		}
	}

	void PlayerScript::giveWater()
	{
		if (mAnimator->IsComplete())
		{
			mState = eState::Idle;
			mAnimator->PlayAnimation(L"Idle", true);
		}
	}
}