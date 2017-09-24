#pragma once

#include "Component.h"

class TransformComponent : public Component
{
	//yeah, I know, encapsulation, but come on, these are going to be constantly accessed.
	//also, it goes against the Hungarian notation a bit. This one always feels like a fight between OCD and convenince.
public:
	int x;
	int y;

	void Init()
	{
		x = 0;
		y = 0;
	}

	void Destroy() {}
	void Update() {}
	void Render() {}
};
