#include "InputHandlingComponent.h"
#include "Entity.h"
#include "SDLApp.h"
#include "TransformComponent.h"

void InputHandlingComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
	m_fSpeed = 1.0f;
	m_vVelocity = Vector2D::Zero;
}

void InputHandlingComponent::Update()
{
	SDL_Event event = SDLApp::GetInstance()->GetEvent();

	if (event.type == SDL_KEYDOWN)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_UP:
			m_vVelocity.y = -m_fSpeed;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			m_vVelocity.y = m_fSpeed;
			break;
		case SDLK_a:
		case SDLK_LEFT:
			m_vVelocity.x = -m_fSpeed;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			m_vVelocity.x = m_fSpeed;
			break;
		default:
			break;
		}
	}

	if (event.type == SDL_KEYUP)
	{
		switch (event.key.keysym.sym)
		{
		case SDLK_w:
		case SDLK_UP:
		case SDLK_s:
		case SDLK_DOWN:
			m_vVelocity.y = 0;
			break;
		case SDLK_a:
		case SDLK_LEFT:
		case SDLK_d:
		case SDLK_RIGHT:
			m_vVelocity.x = 0;
			break;
		default:
			break;
		}
	}

	m_pTransform->m_vPosition += m_vVelocity;
}