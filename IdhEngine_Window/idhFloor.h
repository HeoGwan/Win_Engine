#pragma once
#include "..\\IdhEngine_SOURCE\\idhGameObject.h"

namespace idh
{
	class Floor : public GameObject
	{
	public:
		Floor();
		~Floor();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:

	};
}