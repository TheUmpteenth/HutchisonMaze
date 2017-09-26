#pragma once

#include <vector>
#include "Component.h"

class Entity
{
private:
	Entity();
	std::vector<Component*> m_listComponents;
	int m_iID;
	bool m_bActive;

public:
	Entity(int in_id) : m_iID(in_id), m_bActive(true) {}

	inline int GetID() const { return m_iID; }
	inline bool IsActive() const { return m_bActive; }
	inline void SetActive(bool in_active) { m_bActive = in_active; }

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
				castComponent.Destroy();
				m_listComponents.erase(it);
				delete component;
				break;
			}
		}
	}
	void InternalUpdate();
	void InternalRender();
	void DestroyAllComponents();

	virtual void Init() = 0;
	virtual void Destroy() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};
