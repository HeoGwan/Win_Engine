#include "idhGameObject.h"
#include "idhInput.h"

namespace idh
{
	GameObject::GameObject()
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::Update()
	{
		if (Input::GetKey(eKeyCode::A) || Input::GetKey(eKeyCode::Left))
		{
			mX -= 0.01f;
		}
		
		if (Input::GetKey(eKeyCode::D) || Input::GetKey(eKeyCode::Right))
		{
			mX += 0.01f;
		}
		
		if (Input::GetKey(eKeyCode::W) || Input::GetKey(eKeyCode::Up))
		{
			mY -= 0.01f;
		}
		
		if (Input::GetKey(eKeyCode::S) || Input::GetKey(eKeyCode::Down))
		{
			mY += 0.01f;
		}
	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{
		// 파랑 브러쉬 생성
		HBRUSH blueBrush = CreateSolidBrush(RGB(0, 0, 255));

		// 파랑 브러쉬 DC에 선택 그리고 흰색 브러쉬 반환값 반환
		HBRUSH oldBrush = (HBRUSH)SelectObject(hdc, blueBrush);

		HPEN redPen = CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
		HPEN oldPen = (HPEN)SelectObject(hdc, redPen);

		SelectObject(hdc, oldPen);

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);

		// 다시 흰색 원본브러쉬로 선택
		SelectObject(hdc, oldBrush);
		DeleteObject(blueBrush);
		DeleteObject(redPen);
	}
}