#pragma once
#include "..\\IdhEngine_SOURCE\\idhScript.h"
#include "..\\IdhEngine_SOURCE\\idhTexture.h"

namespace idh
{
	class PlayerScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			GiveWater,
			Attack,
		};

		PlayerScript();
		~PlayerScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void AttackEffect();

		void OnCollisionEnter(class Collider* other);
		void OnCollisionStay(class Collider* other);
		void OnCollisionExit(class Collider* other);

		void SetPixelMapTexture(class graphics::Texture* texture) { mPixelMap = texture; }

	private:
		void idle();
		void move();
		void giveWater();

	private:
		eState mState;
		class Animator* mAnimator;
		class graphics::Texture* mPixelMap;
	};
}