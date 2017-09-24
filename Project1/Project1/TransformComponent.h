#pragma once
#ifndef __DAVIES_TRANSFORM_COMPONENT_HEADER__
#define __DAVIES_TRANSFORM_COMPONENT_HEADER__

#include "Component.h"

class TransformComponent : public Component
{
	//yeah, I know, encapsulation, but come on, these are going to be constantly accessed.
public:
	int x;
	int y;

	void Init()
	{
		x = 0;
		y = 0;
	}
};

#endif//__DAVIES_TRANSFORM_COMPONENT_HEADER__
