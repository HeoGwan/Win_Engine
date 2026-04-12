#pragma once
#include "idhCollider.h"

namespace idh
{
	class CircleCollider2D : public Collider
	{
	public:
		CircleCollider2D();
		~CircleCollider2D();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		float mRadius;
	};
}
