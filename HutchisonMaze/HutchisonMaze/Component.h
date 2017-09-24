#pragma once

class Entity;

class Component
{
private:
	bool m_bActive;

protected:
	Entity* m_pParent;

public:
	Component() : m_bActive(true) {};
	virtual ~Component() {}
	inline void SetActive(bool in_active) { m_bActive = in_active; }
	inline bool IsActive() const { return m_bActive; }
	inline void SetParent(Entity* in_parent) { m_pParent = in_parent; }

	virtual void Init() = 0;
	virtual void Destroy() = 0;
	virtual void Update() = 0;
	virtual void Render() = 0;
};
