#pragma once
#include "..\\IdhEngine_SOURCE\\idhResources.h"
#include "..\\IdhEngine_SOURCE\\idhTexture.h"

namespace idh
{
	void LoadResources()
	{
		Resources::Load<graphics::Texture>(L"BG", L"C:\\Users\\DSU\\Desktop\\04_Study\\02_C++\\Editor_Window\\IdhEngine\\Resources\\CloudOcean.png");
	}
}