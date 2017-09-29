#include "SDL.h"
#include "SDLApp.h"
#include "EntityManager.h"
#include "TextureManager.h"
#include "CollisionManager.h"
#include "Player.h"
#include "Maze.h"

SDLApp::SDLApp()
{
	m_bRunning = false;
	m_pRenderer = NULL;
	m_pWindow = NULL;
}

SDLApp::~SDLApp()
{
	if (m_pWindow != NULL)
	{
		SDL_DestroyWindow(m_pWindow);
	}
	if (m_pRenderer != NULL)
	{
		SDL_DestroyRenderer(m_pRenderer);
	}
	EntityManager::GetInstance()->Destroy();
	TextureManager::GetInstance()->Destroy();
	CollisionManager::GetInstance()->Destroy();
	SDL_Quit();

	std::cout << "SDL App Destroyed" << std::endl;
}

void SDLApp::Init(const char* in_title, int in_width, int in_height, bool in_fullscreen)
{
	int windowFlags = 0;
	if (in_fullscreen)
	{
		windowFlags &= SDL_WINDOW_FULLSCREEN;
	}

	int success = SDL_Init(SDL_INIT_EVERYTHING);
	if (success != 0)
	{
		std::cout << "SDL failed to initialise with code " << success << std::endl;
		exit(0);
	}
	m_pWindow = SDL_CreateWindow("Maze Game For Hutchison Technologies", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
	m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
	m_bRunning = true;

	Player* player = EntityManager::GetInstance()->CreateEntity<Player>();
	Maze* maze = new Maze();
	std::vector<CollisionLayer> vec = { COLLISION_LAYER_WALL };
	CollisionManager::GetInstance()->SetupCollisionLayer(COLLISION_LAYER_PLAYER, vec);
}

void SDLApp::HandleEvents()
{
	SDL_PollEvent(&m_event);

	switch (m_event.type)
	{
		case SDL_QUIT:
			std::cout << "SDL recieved quit signal" << std::endl;
			m_bRunning = false;
			break;

		default:
			break;
	}
}

void SDLApp::Update()
{
	EntityManager::GetInstance()->Update();
	CollisionManager::GetInstance()->Update();
}

void SDLApp::Render()
{
	//	SDL_SetRenderDrawColor(m_pRenderer, 0, 255, 0, 255);
	SDL_RenderClear(m_pRenderer);
	EntityManager::GetInstance()->Render();
	TextureManager::GetInstance()->Render();
	SDL_RenderPresent(m_pRenderer);
}