#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

#define deg2rad(angleDegrees) (angleDegrees * M_PI / 180.0)
#define rad2deg(rad) (rad * (180/M_PI))

typedef enum {
	KEY_W,
	KEY_S,
	KEY_D,
	KEY_A
} keys;

void controlesjogo();
void sys_update();
bool sys_getkeystate(keys key);

typedef struct {
	float x, y;
} vec2;

int rodando = 1;
SDL_Event event;
static SDL_Renderer *renderizador;

vec2 sum(vec2 a, vec2 b)
{
	vec2 ret = {
		a.x + b.x,
		a.y + b.y
	};

	return ret;
}

int main(void) {	
	SDL_Window * janela;
	SDL_Texture * telaDeFundo;
	SDL_Texture * logo;
	SDL_Rect logoRect;
	logoRect.x = 212;
	logoRect.y = 134;
	logoRect.w = 854;
	logoRect.h = 450;
	SDL_Texture * p1;
	SDL_Rect p1Rect;
	p1Rect.x = 640.0;
	p1Rect.y = 360.0;
	p1Rect.w = 32;
	p1Rect.h = 32;
	janela = SDL_CreateWindow("Space Rage", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN_DESKTOP);
	renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
	telaDeFundo = IMG_LoadTexture(renderizador, "intro.png");
	logo = IMG_LoadTexture(renderizador, "sp.png");

	game_init();
	

	SDL_RenderCopy(renderizador, telaDeFundo, NULL, NULL);
	SDL_RenderPresent(renderizador);
	//SDL_Delay(1000);
	SDL_RenderCopy(renderizador, logo, NULL, &logoRect);
	SDL_RenderPresent(renderizador);
	//SDL_Delay(3000);
	while(rodando == 1){
		sys_update();
		SDL_RenderClear(renderizador);

		game_update();

		game_draw();
		SDL_RenderPresent(renderizador);
		SDL_Delay(1000/60);
	}
	SDL_DestroyTexture(logo);
	SDL_DestroyTexture(telaDeFundo);
	SDL_DestroyRenderer(renderizador);
	SDL_DestroyWindow(janela);
	return 0;
}

bool keyarray[sizeof(keys) + 1];

bool sys_getkeystate(keys key)
{
	return keyarray[key];
}

void sys_update(void) {
	while(SDL_PollEvent(&event)){
		if (event.type == SDL_QUIT) {
				rodando = 0;
		}
		if (event.type == SDL_KEYDOWN) {
			switch (event.key.keysym.sym) {
				case SDLK_w:
					keyarray[KEY_W] = true;
					break;

				case SDLK_d:
					keyarray[KEY_D] = true;
					break;

				case SDLK_a:
					keyarray[KEY_A] = true;
					break;

				case SDLK_s:
					keyarray[KEY_S] = true;
					break;

				case SDLK_ESCAPE:
					SDL_QUIT;
					break;
			}
		}

		if (event.type == SDL_KEYUP) {
			switch (event.key.keysym.sym) {
				case SDLK_w:
					keyarray[KEY_W] = false;
					break;

				case SDLK_d:
					keyarray[KEY_D] = false;
					break;

				case SDLK_a:
					keyarray[KEY_A] = false;
					break;

				case SDLK_s:
					keyarray[KEY_S] = false;
					break;
			}
		}
	}
}

SDL_Renderer* sys_get_renderer(void)
{
	return renderizador;
}