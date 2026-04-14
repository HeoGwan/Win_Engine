#pragma once
#include "..\\IdhEngine_SOURCE\\idhScript.h"

namespace idh
{
	class FloorScript : public Script
	{
	public:
		FloorScript();
		~FloorScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

		void OnCollisionEnter(class Collider* other);
		void OnCollisionStay(class Collider* other);
		void OnCollisionExit(class Collider* other);

	private:
	};
}