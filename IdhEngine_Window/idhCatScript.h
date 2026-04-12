#pragma once
#include "..\\IdhEngine_SOURCE\\idhScript.h"
#include "..\\IdhEngine_SOURCE\\idhTransform.h"

namespace idh
{
	class CatScript : public Script
	{
	public:
		enum class eState
		{
			Idle,
			Walk,
			Sleep,
			LayDown,
			Attack,
		};

		enum class eDirection
		{
			Left,
			Right,
			Down,
			Up,
			End,
		};

		CatScript();
		~CatScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void SetPlayer(GameObject* player) { mPlayer = player; }

		Vector2 mDest;
	private:
		void idle();
		void move();
		void layDown();
		void playerWalkAnimationByDirection(eDirection mDirection);
		void translate(Transform* tr);


	private:
		eState mState;
		eDirection mDirection;
		class Animator* mAnimator;
		float mTime;
		float mDeathTime;

		GameObject* mPlayer;
		float mRadian;
	};
}