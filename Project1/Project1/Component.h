#pragma once
#ifndef __DAVIES_SDL_APP_COMPONENT_HEADER__
#define __DAVIES_SDL_APP_COMPONENT_HEADER__

class Entity;

class Component
{
private:
	bool m_active;

protected:
	Entity* m_pParent;

public:
	Component() : m_active(true) {};
	virtual ~Component() {}
	inline void SetActive(bool in_active) { m_active = in_active; }
	inline bool IsActive() const { return m_active; }
	inline void SetParent(Entity* in_parent) { m_pParent = in_parent; }

	virtual void Init() {}
	virtual void Destroy() {}
	virtual void Update() {}
	virtual void Render() {}
};

#endif//__DAVIES_SDL_APP_COMPONENT_HEADER__
