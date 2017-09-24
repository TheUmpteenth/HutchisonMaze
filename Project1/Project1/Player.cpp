#include "Player.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"

void Player::Init()
{
	AddComponent<TransformComponent>();
	AddComponent<SpriteComponent>();
}

void Player::Update()
{

}
