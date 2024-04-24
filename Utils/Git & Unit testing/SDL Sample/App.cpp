#include "App.hpp"
#include <stdexcept>
 
App::App(){

    Init();
    Running = true;

}

App::~App(){
    Cleanup();
}

void App::Init(){

    if(SDL_Init(SDL_INIT_EVERYTHING) < 0) throw std::logic_error("Couldn't initialize SDL");

    window = SDL_CreateWindow("Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

    if(!window){

        Cleanup();
        throw std::logic_error("Couldn't create window");

    }

}
 
int App::Execute(){

    SDL_Event Event;

    while(Running){
        // Process all of the events for the current frame
        while(SDL_PollEvent(&Event)) ProcessEvent(&Event);
    	// Update internal logic
        Loop();
        // Render stuff on the screen
        Render();
    }

    Cleanup();

    return 0;

}

void App::Loop(){}
void App::Render(){}

void App::ProcessEvent(SDL_Event *Event){
    if(Event->type == SDL_QUIT) Running = false;
}

void App::Cleanup(){
    SDL_Quit();
}