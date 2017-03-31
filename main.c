#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <math.h>

#define degreesToRadians(angleDegrees) (angleDegrees * M_PI / 180.0)

void controlesjogo();
	int rodando = 1;
	double angulo = 0;
	double p1Vel = 0;
	SDL_Event event;
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
	SDL_Texture * p1;
	SDL_Rect p1Rect;
	p1Rect.x = 640.0;
	p1Rect.y = 360.0;
	p1Rect.w = 32;
	p1Rect.h = 32;
	janela = SDL_CreateWindow("Space Rage", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, SDL_WINDOW_FULLSCREEN);
	renderizador = SDL_CreateRenderer(janela, -1, SDL_RENDERER_ACCELERATED);
	telaDeFundo = IMG_LoadTexture(renderizador, "intro.png");
	logo = IMG_LoadTexture(renderizador, "sp.png");
	p1 = IMG_LoadTexture(renderizador, "p1basic.png");
	SDL_RenderCopy(renderizador, telaDeFundo, NULL, NULL);
	SDL_RenderPresent(renderizador);
	SDL_Delay(1000);
	SDL_RenderCopy(renderizador, logo, NULL, &logoRect);
	SDL_RenderPresent(renderizador);
	SDL_Delay(3000);
	while(rodando == 1){
		controlesjogo();
		SDL_RenderClear(renderizador);
		/*p1Rect.x += (cos(degreesToRadians(angulo))*p1Vel);
		printf("p1rect.x: %d\n", p1Rect.x);
		p1Rect.y += (sin(degreesToRadians(angulo))*p1Vel);*/
		if(angulo == 0){
			p1Rect.x += p1Vel;
		}
		if(angulo == 45){
			p1Rect.x += p1Vel;
			p1Rect.y += p1Vel;
		}
		if(angulo == -45){
			p1Rect.x += p1Vel;
			p1Rect.y -= p1Vel;
		}
		if(angulo == 90){
			p1Rect.y += p1Vel;
		}
		if(angulo == -90){
			p1Rect.y -= p1Vel;
		}
		if(angulo == 135){
			p1Rect.x -= p1Vel;
			p1Rect.y += p1Vel;
		}
		if(angulo == -135){
			p1Rect.x -= p1Vel;
			p1Rect.y -= p1Vel;
		}
		if(angulo == 180){
			p1Rect.x -= p1Vel;
		}
		if(angulo == -180){
			p1Rect.x -= p1Vel;
		}
		if(angulo == 225){
			p1Rect.x -= p1Vel;
			p1Rect.y -= p1Vel;
		}
		if(angulo == -225){
			p1Rect.x -= p1Vel;
			p1Rect.y += p1Vel;
		}
		if(angulo == 270){
			p1Rect.y -= p1Vel;
		}
		if(angulo == -270){
			p1Rect.y += p1Vel;
		}
		if(angulo == 315){
			p1Rect.x += p1Vel;
			p1Rect.y -= p1Vel;
		}
		if(angulo == -315){
			p1Rect.x += p1Vel;
			p1Rect.y += p1Vel;
		}
		printf("p1rect.y: %d\n", p1Rect.y);
		SDL_RenderCopyEx(renderizador, p1, NULL, &p1Rect, angulo, NULL, SDL_FLIP_VERTICAL);
		SDL_RenderPresent(renderizador);
		SDL_Delay(1000/60);
	}
	SDL_DestroyTexture(logo);
	SDL_DestroyTexture(telaDeFundo);
	SDL_DestroyRenderer(renderizador);
	SDL_DestroyWindow(janela);
	return 0;
}

void controlesjogo(){
	while(SDL_PollEvent(&event)){
		if(event.type == SDL_QUIT){
				rodando = 0;
		}
		if(event.type == SDL_KEYDOWN){
			switch (event.key.keysym.sym){
				case SDLK_w:
					p1Vel+=2;
					break;

				case SDLK_d:
					angulo-=45;
					if(angulo == 360 || angulo == -360)
						angulo = 0;
					printf("d\n");
					printf("angulo: %f\n", angulo);
					break;

				case SDLK_a:
					angulo+=45;
					if(angulo == 360 || angulo == -360)
						angulo = 0;	
					printf("a\n");
					printf("angulo: %f\n", angulo);
					break;

				case SDLK_s:
					p1Vel-=2;
					break;

				case SDLK_ESCAPE:
					SDL_QUIT;
					break;
			}
		}
	}
}
