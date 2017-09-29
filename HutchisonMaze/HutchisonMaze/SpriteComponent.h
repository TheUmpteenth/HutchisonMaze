#pragma once
#include "Component.h"
#include <string>
#include <SDL.h>
#include "Vector2D.h"

class TransformComponent;

class SpriteComponent : public Component
{
private:
	std::string m_subTextureID;

	//note c++11 stye init would be 
	//TransformComponent* m_pTransform {nullptr}
	TransformComponent* m_pTransform = NULL;

	Vector2D m_vSize = Vector2D::Zero;

	SDL_Rect m_rectDestination;

public:
	inline SDL_Rect GetDrawRect() const { return m_rectDestination; }
	void Init();
	void Update();
	void Render();
	void Destroy() { m_pTransform = NULL; }

	inline Vector2D GetSize() const { return m_vSize; }
	void SetSize(const Vector2D& in_vSize);
	inline void SetSubTexture(std::string in_subTextureID) { m_subTextureID = in_subTextureID; }
};
