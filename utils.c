#include "utils.h"
#include "game.h"

void die()
{
    fprintf(stderr, "%s\n", SDL_GetError());
    exit(-1);
}

void draw_image(SDL_Surface *screen, SDL_Surface *image, int x, int y)
{
    SDL_Rect dsrect = {.h=image->h, .w=image->w, .x=x, .y=y};
    SDL_BlitSurface(image, NULL, screen, &dsrect);
}

void render_text(SDL_Surface *surface, TTF_Font *font,  const char *text, SDL_Color color, int x, int y)
{
	SDL_Rect titlepos;
	titlepos.x=x;
	titlepos.y=y;
	//title

	SDL_Surface *blended_text = TTF_RenderText_Blended(font, text, color);

    SDL_BlitSurface(blended_text, NULL, surface, &titlepos);
}
