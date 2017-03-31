#include "game.h"

typedef struct {
	SDL_Texture *sprite;
	float angle;
	vec2 pos, vel;
} entity;

static entity player;

void game_init(void)
{
	player.sprite = IMG_LoadTexture(sys_get_renderer(), "p1basic.png");
}

void game_update(void)
{
	if (sys_getkeystate(KEY_A)) {
		player.angle -= deg2rad(1.5f);
	}

	if (sys_getkeystate(KEY_D)) {
		player.angle += deg2rad(1.5f);
	}

	if (sys_getkeystate(KEY_W)) {
		vec2 enginevec = {
			cosf(player.angle) * 0.1,
			sinf(player.angle) * 0.1
		};

		player.vel = sum(player.vel, enginevec);
	}

	if (sys_getkeystate(KEY_S)) {
		vec2 enginevec = {
			cosf(player.angle) * 0.1,
			sinf(player.angle) * 0.1
		};

		enginevec.x *= -1;
		enginevec.y *= -1;

		player.vel = sum(player.vel, enginevec);
	}

	player.pos = sum(player.pos, player.vel);

	p1Rect.x = player.pos.x;
	p1Rect.y = player.pos.y;
}

void game_draw()
{
	SDL_Renderer *renderizador = sys_get_renderer();

	SDL_RenderCopyEx(renderizador, player.sprite, NULL, &p1Rect, rad2deg(player.angle), NULL, SDL_FLIP_VERTICAL);
}