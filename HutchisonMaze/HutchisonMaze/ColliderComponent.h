#pragma once
#include <string>
#include "SDL.h"
#include "Component.h"
#include "Vector2D.h"

class TransformComponent;
enum CollisionLayer;

class ColliderComponent : public Component
{
private:
	SDL_Rect m_rectCollider;
	CollisionLayer m_eLayer;

	//note c++11 stye init would be 
	//TransformComponent* m_pTransform {nullptr}
	TransformComponent* m_pTransform = NULL;

	Vector2D m_vSize = Vector2D::Zero;
public:
	inline SDL_Rect GetAABB() const { return m_rectCollider; }
	inline CollisionLayer GetTag() const { return m_eLayer; }
	void SetCollisionLayer(CollisionLayer in_eLayer);
	inline float GetWidth() const { return m_vSize.x; }
	inline void SetWidth(const float& in_iWidth) { m_vSize.x = in_iWidth; }
	inline float GetHeight() const { return m_vSize.y; }
	inline void SetHeight(const float& in_iHeight) { m_vSize.y = in_iHeight; }

	void ReportCollision(const ColliderComponent &in_colliderHit);

	void Init();
	void Update();
	void Render() {}
	void Destroy() { m_pTransform = NULL; }
};