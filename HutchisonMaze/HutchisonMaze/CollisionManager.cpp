#include "CollisionManager.h"
#include "ColliderComponent.h"
#include "CollisionUtils.h"


CollisionManager::~CollisionManager()
{
	m_mapColliderLists.clear();
	m_mapCollisionLayersLists.clear();
}

void CollisionManager::RegisterCollider(ColliderComponent& in_colliderComponent)
{
	m_mapColliderLists[in_colliderComponent.GetTag()].push_back(&in_colliderComponent);
}

void CollisionManager::SetupCollisionLayer(const CollisionLayer &in_Layer, std::vector<CollisionLayer> &in_listLayersToCollideWith)
{
	m_mapCollisionLayersLists[in_Layer] = in_listLayersToCollideWith;
}

void CollisionManager::Update()
{
	for (std::map<CollisionLayer, std::vector<CollisionLayer>>::iterator outer = m_mapCollisionLayersLists.begin(); outer != m_mapCollisionLayersLists.end(); ++outer)
	{
		for (std::vector<CollisionLayer>::iterator inner = outer->second.begin(); inner != outer->second.end(); ++inner)
		{
			for (std::vector<ColliderComponent*>::iterator colliderIterA = m_mapColliderLists[outer->first].begin(); colliderIterA != m_mapColliderLists[outer->first].end(); ++colliderIterA)
			{
				for (std::vector<ColliderComponent*>::iterator colliderIterB = m_mapColliderLists[*inner].begin(); colliderIterB != m_mapColliderLists[*inner].end(); ++colliderIterB)
				{
					if (CollisionUtils::AABBinAABB((*colliderIterA)->GetAABB(), (*colliderIterB)->GetAABB()))
					{
						(*colliderIterA)->ReportCollision(**colliderIterB);
					}
				}
			}
		}
	}
}
