#include "idhDestroy.h"
#include "idhGameObject.h"

namespace idh::object
{
	void Destroy(GameObject* obj)
	{
		obj->Death();
	}
}