#include "WallEntity.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "ColliderComponent.h"
#include "CollisionManager.h"

void WallEntity::Init()
{
	AddComponent<TransformComponent>();
	AddComponent<SpriteComponent>();
	AddComponent<ColliderComponent>()->SetCollisionLayer(COLLISION_LAYER_WALL);
}