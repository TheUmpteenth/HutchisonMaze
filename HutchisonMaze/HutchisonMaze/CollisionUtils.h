#pragma once
#include <SDL.h>

class CollisionUtils
{
public:
	static bool AABBinAABB(const SDL_Rect& in_a, const SDL_Rect& in_b);
};