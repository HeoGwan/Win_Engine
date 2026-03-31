#pragma once
#include "idhScene.h"

namespace idh
{
	class TitleScene : public Scene
	{
	public:
		TitleScene();
		~TitleScene();

		void Initialize() override;
		void Update() override;
		void LateUpdate() override;
		void Render(HDC hdc) override;

	private:
		class GameObject* bg;
		class GameObject* title;
	};
}
