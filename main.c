#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
int main(){
	SDL_Window * janela;
	SDL_Renderer * renderizador;
	SDL_Texture * telaDeFundo;
	janela = SDL_CreateWindow("Space Rage", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_FULLSCREEN_DESKTOP);
	renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
	telaDeFundo = IMG_LoadTexture(renderizador, "intro.png");
	SDL_RenderCopy(renderizador, telaDeFundo, NULL, NULL);
	SDL_RenderPresent(renderizador);
	SDL_Delay(5000);
	SDL_DestroyTexture(telaDeFundo);
	SDL_DestroyRenderer(renderizador);
	SDL_DestroyWindow(janela);
	return 0;
}
