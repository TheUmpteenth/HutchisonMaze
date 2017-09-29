#include "CollisionUtils.h"

bool CollisionUtils::AABBinAABB(const SDL_Rect& in_rectA, const SDL_Rect& in_rectB)
{
	return (in_rectA.x + in_rectA.w > in_rectB.x &&
		in_rectB.x + in_rectB.w > in_rectA.x &&
		in_rectA.y + in_rectA.h > in_rectB.y &&
		in_rectB.y + in_rectB.h > in_rectA.y);
}