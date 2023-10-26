#ifndef DRAWING_H_
#define DRAWING_H_

#include "defs.h"
#include "game.h"
#include "utils.h"

void draw_board(SDL_Surface *screen, const game_t game);
void draw_game(SDL_Surface *screen, const game_t game);

#endif //DRAWING_H_

