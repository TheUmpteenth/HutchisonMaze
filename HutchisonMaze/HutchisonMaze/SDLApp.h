#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class Maze;

//TODO: Ideally, I'd break off a game class, where game logic would live apart from the app code.
//if I have time, I will do so
class SDLApp : public Singleton<SDLApp>
{
private:
	SDL_Window* m_pWindow = NULL;
	SDL_Renderer* m_pRenderer = NULL;
	bool m_bRunning = false;
	SDL_Event m_event;

	Maze* m_pMaze = NULL;//This should be part of a game class and not here

public:
	SDLApp();
	~SDLApp();

	void Init(const char* in_title, int in_width, int in_height, bool in_fullscreen);
	void HandleEvents();
	void Update();
	void Render();

	inline bool IsRunning() const { return m_bRunning; }
	inline SDL_Window* GetWindow() const { return m_pWindow; }
	inline SDL_Renderer* GetRenderer() const { return m_pRenderer; }
	inline SDL_Event GetEvent() const { return m_event; }
};
