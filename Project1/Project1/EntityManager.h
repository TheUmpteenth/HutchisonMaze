#pragma once
#ifndef __DAVIES_SDL_APP_ENTITY_MANAGER_HEADER__
#define __DAVIES_SDL_APP_ENTITY_MANAGER_HEADER__

#include "Singleton.h"
#include "Entity.h"
#include <vector>

class EntityManager : public Singleton<EntityManager>
{
private:
	int m_iLastID;
	std::vector<Entity*> m_listEntities;

	void AddEntity(Entity* in_entity);
public:
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
};
#endif//__DAVIES_SDL_APP_ENTITY_MANAGER_HEADER__