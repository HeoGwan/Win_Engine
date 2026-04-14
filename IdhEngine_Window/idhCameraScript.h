#pragma once
#include "..\\IdhEngine_SOURCE\\idhScript.h"
#include "..\\IdhEngine_SOURCE\\idhTransform.h"

namespace idh
{
	class CameraScript : public Script
	{
	public:
		CameraScript();
		~CameraScript();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;
	private:
	};
}