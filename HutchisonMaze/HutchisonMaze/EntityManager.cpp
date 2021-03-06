#include "EntityManager.h"

EntityManager::~EntityManager()
{
	DestroyAllEntites();
}

void EntityManager::DestroyEntity(const Entity& in_entity)
{
	for (std::vector<Entity*>::iterator it = m_listEntities.begin(); it != m_listEntities.end(); ++it)
	{
		Entity* entity = *it;
		if (entity->GetID() == in_entity.GetID())
		{
			entity->Destroy();
			m_listEntities.erase(it);
			break;
		}
	}
}

void EntityManager::Update()
{
	for (std::vector<Entity*>::iterator it = m_listEntities.begin(); it != m_listEntities.end(); ++it)
	{
		Entity* entity = *it;
		if (entity->IsActive())
		{
			entity->InternalUpdate();
		}
	}
}

void EntityManager::Render()
{
	for (std::vector<Entity*>::iterator it = m_listEntities.begin(); it != m_listEntities.end(); ++it)
	{
		Entity* entity = *it;
		if (entity->IsActive())
		{
			entity->InternalRender();
		}
	}
}

void EntityManager::AddEntity(Entity* in_entity)
{
	m_listEntities.push_back(in_entity);
}

void EntityManager::DestroyAllEntites()
{
	for (std::vector<Entity*>::iterator it = m_listEntities.begin(); it != m_listEntities.end(); ++it)
	{
		Entity* entity = *it;
		entity->Destroy();
		delete entity;
	}
	m_listEntities.clear();
}
