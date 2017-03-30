#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
int main(){
	SDL_Window * window;
	window = SDL_CreateWindow("Space Rage", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
	SDL_Delay(1000);
	return 0;
}