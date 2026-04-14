#pragma once
#include "idhComponent.h"

namespace idh
{
	class Rigidbody : public Component
	{
	public:
		Rigidbody();
		~Rigidbody();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetMass(float mass) { mMass = mass; }
		void AddForce(Vector2 force) { mForce = force; }
		void SetGround(bool ground) { mbGround = ground; }
		void SetVelocity(Vector2 velocity) { mVelocity = velocity; }
		Vector2 GetVelocity() { return mVelocity; }
		

	private:
		bool mbGround;
		float mMass;
		float mFriction;

		Vector2 mForce;
		Vector2 mAccelation;
		Vector2 mVelocity;
		Vector2 mLimitedVelocity;
		Vector2 mGravity;
	};
}

