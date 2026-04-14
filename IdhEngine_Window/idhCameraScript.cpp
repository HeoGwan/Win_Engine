#include "idhCameraScript.h"
#include "idhInput.h"
#include "idhTransform.h"
#include "idhTime.h"
#include "idhGameObject.h"
#include "idhAnimator.h"
#include "idhCat.h"
#include "idhCatScript.h"
#include "idhObject.h"
#include "idhResources.h"
#include "idhCollider.h"

namespace idh
{
	CameraScript::CameraScript()
	{

	}

	CameraScript::~CameraScript()
	{

	}

	void CameraScript::Initialize()
	{

	}

	void CameraScript::Update()
	{
		Transform* tr = GetOwner()->GetComponent<Transform>();
		Vector2 pos = tr->GetPosition();

		if (Input::GetKey(eKeyCode::Right))
		{
			pos.x += 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Left))
		{
			pos.x -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Up))
		{
			pos.y -= 100.0f * Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::Down))
		{
			pos.y += 100.0f * Time::DeltaTime();
		}

		tr->SetIndexPosition(pos);
	}

	void CameraScript::LateUpdate()
	{

	}

	void CameraScript::Render(HDC hdc)
	{

	}
}