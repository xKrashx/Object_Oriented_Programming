#ifndef _APP_H_
#define _APP_H_

#include <SDL.h>

class App{
public:
    App();
    ~App();

    int Execute();

private:
    void Init();
    void ProcessEvent(SDL_Event *Event);
    void Loop();
    void Render();
    void Cleanup();

private:
    bool Running;
    SDL_Window *window = nullptr;
};

#endif