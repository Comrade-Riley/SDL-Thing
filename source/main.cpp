#include <SDL2/SDL.h>
#include <SDL2/SDL_mixer.h>
#include <iostream>

bool running = true;
SDL_Event e;
const Uint8* keys = SDL_GetKeyboardState(NULL);
SDL_Rect rect = {200,200,25,25};
SDL_Rect imrect = {300,300,100,100};
SDL_Surface* image = SDL_LoadBMP("source/src/images/tux.bmp");

int main(){
    SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO);
    SDL_Window* window = SDL_CreateWindow("win",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,640,480,SDL_WINDOW_OPENGL);
    SDL_Renderer* renderer = SDL_CreateRenderer(window,-1,SDL_RENDERER_ACCELERATED);
    Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,1,2048);
    
    Mix_Music* music = Mix_LoadMUS("source/src/sounds/tux.wav");
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer,image);
    
    while (running){
        while (SDL_PollEvent(&e)){
            if (e.type == SDL_QUIT){
                running = false;
            }
            
            if (keys[SDL_SCANCODE_ESCAPE]){
                running = false;
            }
            
            if (keys[SDL_SCANCODE_UP]){
                imrect.y -= 5;
            }
            if (keys[SDL_SCANCODE_DOWN]){
                imrect.y += 5;
            }
            if (keys[SDL_SCANCODE_RIGHT]){
                imrect.x += 5;
            }            
            if (keys[SDL_SCANCODE_LEFT]){
                imrect.x -= 5;
            }  

            SDL_Point mousePoint = {e.motion.x,e.motion.y};
            if (SDL_EnclosePoints(&mousePoint,1,&imrect,NULL) && SDL_GetMouseState(NULL,NULL) && SDL_BUTTON(2) || SDL_HasIntersection(&rect,&imrect)){
                Mix_PlayMusic(music,1);
            }        
        }
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer,texture,NULL,&imrect);
        SDL_SetRenderDrawColor(renderer,230,0,0,250);
        SDL_RenderFillRect(renderer,&rect);
        SDL_RenderDrawRect(renderer,&rect);
        SDL_SetRenderDrawColor(renderer,0,0,0,250);
        SDL_RenderPresent(renderer);
    }
    void SDL_Quit();
}