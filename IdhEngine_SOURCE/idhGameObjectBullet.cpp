#include "idhGameObjectBullet.h"
#include "idhTime.h"

namespace idh
{
	GameObjectBullet::GameObjectBullet()
		: mX(0.0f)
		, mY(0.0f)
	{
	}

	GameObjectBullet::~GameObjectBullet()
	{
	}

	void GameObjectBullet::Update()
	{
		const int speed = 5000.0f;
		mX += speed * Time::DeltaTime();

		if (mX > 1600)
		{
 			delete this;
		}
	}

	void GameObjectBullet::LateUpdate()
	{

	}

	void GameObjectBullet::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 200, 0));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);

		Ellipse(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		// 다시 흰색 원본브러쉬로 선택
		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}