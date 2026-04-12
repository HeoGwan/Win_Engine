#pragma once
#include "idhCollider.h"

namespace idh
{
	class BoxCollider2D : public Collider
	{
	public:
		BoxCollider2D();
		~BoxCollider2D();

		void Initialize();
		void Update();
		void LateUpdate();
		void Render(HDC hdc);

	private:
		Vector2 mSize;
	};
}