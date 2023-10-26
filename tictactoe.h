#ifndef TICTACTOE_H_
#define TICTACTOE_H_

#include "defs.h"
#include "game.h"

void load_game(game_t *game);
bool is_empty(const game_t game, int x, int y);
void switch_player(game_t *game);
void check_row(game_t *game, int i, int px[N], int po[N]);
void check_diagonal_r(game_t *game, int px[N], int po[N]);
void check_diagonal_l(game_t *game, int px[N], int po[N]);
void check_tie(game_t *game);
void play(game_t *game);

#endif //TICTACTOE_H_
