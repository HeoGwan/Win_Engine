#pragma once
#include "..\\IdhEngine_SOURCE\\idhGameObject.h"

namespace idh
{
	class Player : public GameObject
	{
	public:
		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}