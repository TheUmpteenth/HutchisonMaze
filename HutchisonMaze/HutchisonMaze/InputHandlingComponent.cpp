#include "InputHandlingComponent.h"
#include "Entity.h"
#include "SDLApp.h"
#include "TransformComponent.h"

void InputHandlingComponent::Init()
{
	m_pTransform = m_pParent->GetComponent<TransformComponent>();
	m_fSpeed = 1.0f;
	m_fVelocityX = m_fVelocityY = 0.0f;
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
			m_fVelocityY = -m_fSpeed;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			m_fVelocityY = m_fSpeed;
			break;
		case SDLK_a:
		case SDLK_LEFT:
			m_fVelocityX = -m_fSpeed;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			m_fVelocityX = m_fSpeed;
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
			m_fVelocityY = 0;
			break;
		case SDLK_s:
		case SDLK_DOWN:
			m_fVelocityY = 0;
			break;
		case SDLK_a:
		case SDLK_LEFT:
			m_fVelocityX = 0;
			break;
		case SDLK_d:
		case SDLK_RIGHT:
			m_fVelocityX = 0;
			break;
		default:
			break;
		}
	}

	m_pTransform->m_vPosition.x += m_fVelocityX;
	m_pTransform->m_vPosition.y += m_fVelocityY;
}