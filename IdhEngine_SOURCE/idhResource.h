#pragma once
#include "idhEntity.h"

namespace idh
{
	class Resource : public Entity // 추상 클래스 메모리 할당 x 상속 받아서만 사용해야 한다
	{
	public:
		Resource(enums::eResourceType type);
		virtual ~Resource();

		virtual HRESULT Load(const std::wstring& path) = 0; // 순수 가상 함수 -> 실제 메모리 할당이 불가능해지는 문법

		const std::wstring& GetPath() { return mPath; }
		void SetPath(const std::wstring& path) { mPath = path; }

	private:
		const enums::eResourceType mType;
		std::wstring mPath;
	};
	// Resource test;
	//class Texture : public Resource;
	//class AudioClip : public Resource;
}


// 게임에서 사용되는 데이터들의 종류

// 이미지, 사운드, 

// 저장 게임 플레이데이터
// 이것도 리소스이다