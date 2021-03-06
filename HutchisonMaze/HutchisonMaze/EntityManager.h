#pragma once

#include "Singleton.h"
#include "Entity.h"
#include <vector>

class EntityManager : public Singleton<EntityManager>
{
private:
	int m_iLastID = false;
	std::vector<Entity*> m_listEntities;

	void AddEntity(Entity* in_entity);
public:
	~EntityManager();
	template <class T>
	T* CreateEntity()
	{
		T* entity = new T(++m_iLastID);
		AddEntity(entity);
		entity->Init();
		return entity;
	}
	void DestroyEntity(const Entity& in_entity);
	void Update();
	void Render();
	void DestroyAllEntites();
};
