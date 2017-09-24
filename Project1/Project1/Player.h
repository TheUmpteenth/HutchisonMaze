#pragma once
#ifndef __DAVIES_SDL_APP_PLAYER_ENTITY_HEADER__
#define __DAVIES_SDL_APP_PLAYER_ENTITY_HEADER__

#include "Entity.h"

class Player : public Entity
{
public:
	Player(int in_id) : Entity(in_id) {}

	void Init();
	void Update();
};
#endif//__DAVIES_SDL_APP_PLAYER_ENTITY_HEADER__
