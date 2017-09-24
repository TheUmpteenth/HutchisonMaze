#include "Entity.h"
#include "Component.h"


void Entity::InternalUpdate()
{
	Update();
	for (std::vector<Component*>::iterator it = m_listComponents.begin(); it != m_listComponents.end(); ++it)
	{
		Component* component = *it;
		if (component->IsActive())
		{
			component->Update();
		}
	}
}

void Entity::InternalRender()
{
	Render();
	for (std::vector<Component*>::iterator it = m_listComponents.begin(); it != m_listComponents.end(); ++it)
	{
		Component* component = *it;
		if (component->IsActive())
		{
			component->Render();
		}
	}
}