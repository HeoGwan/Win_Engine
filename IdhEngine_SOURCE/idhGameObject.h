#pragma once
#include "CommonInclude.h"
#include "idhGameObjectBullet.h"
#include "idhComponent.h"

namespace idh
{
	// Actor
	class GameObject
	{
	public:
		GameObject();
		~GameObject();

		virtual void Initialize();
		virtual void Update();
		virtual void LateUpdate();
		virtual void Render(HDC hdc);

		template <typename T>
		T* AddComponent()
		{
			T* comp = new T();
			comp->Initialize();
			comp->SetOwner(this);
			mComponents.push_back(comp);
			return comp;
		}

		template <typename T>
		T* GetComponent()
		{
			T* component = nullptr;
			for (Component* comp : mComponents)
			{
				component = dynamic_cast<T*>(comp);
				if (component)
					break;
			}
			return component;
		}

	private:
		void initializeTransform();

	private:
		//// 게임 오브젝트의 좌표
		//float mX;
		//float mY;
		//std::vector<GameObjectBullet*> bullets;
		std::vector<Component*> mComponents;
	};
}

