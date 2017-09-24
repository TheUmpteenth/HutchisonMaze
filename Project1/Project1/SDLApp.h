#pragma once

#include "Singleton.h"
#include "SDL.h"
#include "SDL_image.h"
#include <iostream>

class SDLApp : public Singleton<SDLApp>
{
private:
	SDL_Window* m_pWindow;
	SDL_Renderer* m_pRenderer;
	bool m_bRunning;

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
};
