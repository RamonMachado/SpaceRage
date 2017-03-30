#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

int main(){
	SDL_Window * janela;
	SDL_Renderer * renderizador;
	SDL_Texture * telaDeFundo;
	SDL_Texture * logo;
	SDL_Rect logoRect;
	logoRect.x = 212;
	logoRect.y = 134;
	logoRect.w = 854;
	logoRect.h = 450;
	janela = SDL_CreateWindow("Space Rage", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN);
	renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
	telaDeFundo = IMG_LoadTexture(renderizador, "intro.png");
	logo = IMG_LoadTexture(renderizador, "sp.png");
	SDL_RenderCopy(renderizador, telaDeFundo, NULL, NULL);
	SDL_RenderPresent(renderizador);
	SDL_Delay(1000);
	SDL_RenderCopy(renderizador, logo, NULL, &logoRect);
	SDL_RenderPresent(renderizador);
	SDL_Delay(3000);
	SDL_DestroyTexture(telaDeFundo);
	SDL_DestroyRenderer(renderizador);
	SDL_DestroyWindow(janela);
	return 0;
}
