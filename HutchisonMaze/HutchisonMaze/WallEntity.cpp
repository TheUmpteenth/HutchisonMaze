#include "WallEntity.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

void WallEntity::Init()
{
	AddComponent<TransformComponent>();
	AddComponent<SpriteComponent>();
}