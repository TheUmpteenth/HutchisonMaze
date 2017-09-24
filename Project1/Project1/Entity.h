#pragma once
#ifndef __DAVIES_SDL_APP_ENTITY_HEADER__
#define __DAVIES_SDL_APP_ENTITY_HEADER__

#include <vector>
#include "Component.h"

class Entity
{
private:
	Entity();
	std::vector<Component*> m_listComponents;
	int m_id;
	bool m_active;

public:
	Entity(int in_id) : m_id(in_id), m_active(true) {}

	inline int GetID() const { return m_id; }
	inline bool IsActive() const { return m_active; }
	inline void SetActive(bool in_active) { m_active = in_active; }

	template <class T>
	T* AddComponent()
	{
		T* component = new T();
		m_listComponents.push_back((Component*)component);
		component->SetParent(this);
		component->Init();
		return component;
	}

	template <class T>
	T* GetComponent()
	{
		for (std::vector<Component*>::iterator it = m_listComponents.begin(); it != m_listComponents.end(); ++it)
		{
			Component* component = *it;
			T* castComponent = dynamic_cast<T*>(component);
			if (castComponent != NULL)
			{
				return castComponent;
			}
		}
		return NULL;
	}

	template <class T>
	void RemoveComponent()
	{
		for (std::vector<Component*>::iterator it = m_listComponents.begin(); it != m_listComponents.end(); ++it)
		{
			Component* component = *it;
			T* castComponent = dynamic_cast<T*>(component);
			if (castComponent != NULL)
			{
				m_listComponents.erase(it);
				break;
			}
		}
	}
	void InternalUpdate();
	void InternalRender();

	virtual void Init() {}
	virtual void Destroy() {}
	virtual void Update() {}
	virtual void Render() {}
};
#endif//__DAVIES_SDL_APP_ENTITY_HEADER__