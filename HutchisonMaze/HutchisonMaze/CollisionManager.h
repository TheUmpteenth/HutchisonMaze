#pragma once
#include <map>
#include <vector>
#include <string>
#include "Singleton.h"

class ColliderComponent;

enum CollisionLayer
{
	COLLISION_LAYER_PLAYER,
	COLLISION_LAYER_WALL,
	COLLISION_LAYER_TOTAL
};

class CollisionManager : public Singleton<CollisionManager>
{
private:
	std::map<CollisionLayer, std::vector<ColliderComponent*>> m_mapColliderLists;
	std::map<CollisionLayer, std::vector<CollisionLayer>> m_mapCollisionLayersLists;
	
public:
	~CollisionManager();
	void RegisterCollider(ColliderComponent& in_colliderComponent);
	void SetupCollisionLayer(const CollisionLayer &in_Layer, std::vector<CollisionLayer> &in_listLayersToCollideWith);
	void Update();
};
