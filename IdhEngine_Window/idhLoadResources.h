#pragma once
#include "..\\IdhEngine_SOURCE\\idhResources.h"
#include "..\\IdhEngine_SOURCE\\idhTexture.h"

namespace idh
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"Map", L"..\\Resources\\img\\map\\map_pure.png");
		Resources::Load<graphics::Texture>(L"PackMan", L"..\\Resources\\img\\pacman\\0.png");
	}
}