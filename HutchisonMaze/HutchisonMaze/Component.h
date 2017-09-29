#pragma once

class Entity;

//I saw some nice code for indexing these that involved declaring a static int from within a function, but wasn't convinced that it would be compliant pre c++11
//TODO: switch to this type of indexing as an optimisation, it will eliminate the slow dynamic_cast

class Component
{
private:
	bool m_bActive = false;

protected:
	Entity* m_pParent = 0;

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
