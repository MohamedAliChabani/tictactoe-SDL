#ifndef UTILS_H_
#define UTILS_H_

#include "defs.h"
#include "game.h"

void die();
void draw_image(SDL_Surface *screen, SDL_Surface *image, int x, int y);
void render_text(SDL_Surface *surface, TTF_Font *font,  const char *text, SDL_Color color, int x, int y);

#endif //UTILS_H_
