#include "../h/Platform.hpp"
#include <SDL3/SDL.h>

Platform::Platform(char const* title, int windowWidth, int windowHeight, int textureWidth, int textureHeight)
{
    if (!SDL_Init(SDL_INIT_VIDEO))
    {
        SDL_Log("SDL could not initialize! SDL Error: %s", SDL_GetError());
        return;
    }

    window = SDL_CreateWindow(title, windowWidth, windowHeight, SDL_WINDOW_RESIZABLE);

    if (!window)
    {
        SDL_Log("Window could not be created! SDL Error: %s", SDL_GetError());
        return;
    }

    renderer = SDL_CreateRenderer(window, nullptr);

    if (!renderer)
    {
        SDL_Log("Renderer could not be created! SDL Error: %s", SDL_GetError());
        return;
    }

    texture = SDL_CreateTexture(
            renderer,
            SDL_PIXELFORMAT_RGBA8888,
            SDL_TEXTUREACCESS_STREAMING,
            textureWidth,
            textureHeight
    );

    if (!texture)
    {
        SDL_Log("Texture could not be created! SDL Error: %s", SDL_GetError());
        return;
    }
}

Platform::~Platform()
{
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void Platform::Update(void const* buffer, int pitch)
{
    SDL_UpdateTexture(texture, nullptr, buffer, pitch);
    SDL_RenderClear(renderer);
    SDL_RenderTexture(renderer, texture, nullptr, nullptr);
    SDL_RenderPresent(renderer);
}

bool Platform::ProcessInput(uint8_t* keys)
{
    bool quit = false;
    SDL_Event event;

    while (SDL_PollEvent(&event))
    {
        switch (event.type)
        {
            case SDL_EVENT_QUIT:
                quit = true;
                break;

            case SDL_EVENT_KEY_DOWN:
                switch (event.key.key)
                {
                    case SDLK_ESCAPE: quit = true; break;
                    case SDLK_X: keys[0] = 1; break;
                    case SDLK_1: keys[1] = 1; break;
                    case SDLK_2: keys[2] = 1; break;
                    case SDLK_3: keys[3] = 1; break;
                    case SDLK_Q: keys[4] = 1; break;
                    case SDLK_W: keys[5] = 1; break;
                    case SDLK_E: keys[6] = 1; break;
                    case SDLK_A: keys[7] = 1; break;
                    case SDLK_S: keys[8] = 1; break;
                    case SDLK_D: keys[9] = 1; break;
                    case SDLK_Z: keys[0xA] = 1; break;
                    case SDLK_C: keys[0xB] = 1; break;
                    case SDLK_4: keys[0xC] = 1; break;
                    case SDLK_R: keys[0xD] = 1; break;
                    case SDLK_F: keys[0xE] = 1; break;
                    case SDLK_V: keys[0xF] = 1; break;
                }
                break;

            case SDL_EVENT_KEY_UP:
                switch (event.key.key)
                {
                    case SDLK_X: keys[0] = 0; break;
                    case SDLK_1: keys[1] = 0; break;
                    case SDLK_2: keys[2] = 0; break;
                    case SDLK_3: keys[3] = 0; break;
                    case SDLK_Q: keys[4] = 0; break;
                    case SDLK_W: keys[5] = 0; break;
                    case SDLK_E: keys[6] = 0; break;
                    case SDLK_A: keys[7] = 0; break;
                    case SDLK_S: keys[8] = 0; break;
                    case SDLK_D: keys[9] = 0; break;
                    case SDLK_Z: keys[0xA] = 0; break;
                    case SDLK_C: keys[0xB] = 0; break;
                    case SDLK_4: keys[0xC] = 0; break;
                    case SDLK_R: keys[0xD] = 0; break;
                    case SDLK_F: keys[0xE] = 0; break;
                    case SDLK_V: keys[0xF] = 0; break;
                }
                break;
        }
    }

    return quit;
}