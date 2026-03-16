#include "idhGameObject.h"
#include "idhInput.h"
#include "idhTime.h"
#include <algorithm>

namespace idh
{
	GameObject::GameObject()
		: mX(0.0f)
		, mY(0.0f)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		const int speed = 100.0f;
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= speed * Time::DeltaTime();
		}
		
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += speed * Time::DeltaTime();
		}
		
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= speed * Time::DeltaTime();
		}
		
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += speed * Time::DeltaTime();
		}

		if (Input::GetKeyDown(eKeyCode::Space))
		{
			// 총알을 생성한다
			//GameObjectBullet* bullet = new GameObjectBullet();
			GameObjectBullet* bullet = new GameObjectBullet();
			bullet->SetPosition(mX, mY);
			bullets.push_back(bullet);
			//bullets.push_back(bullet);
		}

		std::for_each(bullets.begin(), bullets.end(),
			[&](GameObjectBullet* bullet) -> void
			{
				bullet->Update();
			});
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(rand() % 255, rand() % 255, rand() % 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(rand() % 255, rand() % 255, rand() % 255));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);

		Ellipse(hdc, mX, mY, 200 + mX, 200 + mY);

		// 다시 흰색 원본브러쉬로 선택
		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);

		std::for_each(bullets.begin(), bullets.end(),
			[&](GameObjectBullet* bullet) -> void
			{
				bullet->Render(hdc);
			});
	}
}