#pragma once
#include "CommonInclude.h"
#include "idhEntity.h"

namespace idh
{
	using namespace enums;
	class UIBase : public Entity
	{
	public:
		UIBase();
		~UIBase();

		/// <summary>
		/// ui가 로드 되었을 때 초기화 해주는 함수
		/// </summary>
		void Initialize();
		/// <summary>
		/// ui가 활성화되면 호출되는 함수
		/// </summary>
		void Active();
		/// <summary>
		/// ui가 비활성화되면 호출되는 함수
		/// </summary>
		void InActive();		
		void Update();
		void LateUpdate();
		void Render(HDC hdc);
		/// <summary>
		/// UI가 사라질 때 호출되는 함수
		/// </summary>
		void UIClear();

		virtual void OnInit();
		virtual void OnActive();
		virtual void OnInActive();
		virtual void OnUpdate();
		virtual void OnClear();

		eUIType GetType() { return mType; }
		void SetFullScreen(bool enable) { mbFullScreen = enable; }
		bool IsFullScreen() { return mbFullScreen; }

	private:
		eUIType mType;
		bool mbFullScreen;
		bool mbEnabled;

	};
}