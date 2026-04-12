#include "idhCollider.h"

namespace idh
{
	Collider::Collider()
		: Component(enums::eComponentType::Collider)
		, mOffset(Vector2::Zero)
	{

	}

	Collider::~Collider()
	{

	}

	void Collider::Initialize()
	{
	}

	void Collider::Update()
	{

	}

	void Collider::LateUpdate()
	{

	}

	void Collider::Render(HDC hdc)
	{
	}
}