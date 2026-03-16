#pragma once
#include "CommonInclude.h"

namespace idh
{
	class GameObjectBullet
	{
	public:
		GameObjectBullet();
		~GameObjectBullet();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y)
		{
			mX = x;
			mY = y;
		}

		float GetPositionX() { return mX; }
		float GetPositionY() { return mY; }


	private:
		// 게임 오브젝트의 좌표
		float mX;
		float mY;
	};
}
