#include "Player.h"
#include "SpriteComponent.h"
#include "TransformComponent.h"
#include "InputHandlingComponent.h"

void Player::Init()
{
	AddComponent<TransformComponent>();
	AddComponent<SpriteComponent>();
	AddComponent<InputHandlingComponent>();
}

void Player::Update()
{

}
