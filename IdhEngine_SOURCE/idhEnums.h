#pragma once

namespace idh::enums
{
	enum class eLayerType
	{
		None,
		BackGround,
		//Tree
		//Character
		Player,
		Max = 16,
	};

	enum class eResourceType
	{
		Texture,
		AudioClip,
		Prefab,
		End,
	};
}