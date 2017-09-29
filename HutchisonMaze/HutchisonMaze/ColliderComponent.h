#pragma once
#include <string>
#include "SDL.h"
#include "Component.h"

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

	int m_iWidth = 0;
	int m_iHeight = 0;
public:
	inline SDL_Rect GetAABB() const { return m_rectCollider; }
	inline CollisionLayer GetTag() const { return m_eLayer; }
	void SetCollisionLayer(CollisionLayer in_eLayer);
	inline int GetWidth() const { return m_iWidth; }
	inline void SetWidth(const int& in_iWidth) { m_iWidth = in_iWidth; }
	inline int GetHeight() const { return m_iHeight; }
	inline void SetHeight(const int& in_iHeight) { m_iHeight = in_iHeight; }

	void ReportCollision(const ColliderComponent &in_colliderHit);

	void Init();
	void Update();
	void Render() {}
	void Destroy() { m_pTransform = NULL; }
};