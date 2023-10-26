#include "tictactoe.h"

void load_game(game_t *game)
{
    game->state = RUNNING_STATE;
    game->player = PLAYER_X;

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            game->board[i][j] = 0;
        }
    }
}

bool is_empty(const game_t game, int x, int y)
{
    if (game.board[x][y] == PLAYER_X || game.board[x][y] == PLAYER_O)
        return false;
    return true;
}

void switch_player(game_t *game)
{
    game->player = (game->player == PLAYER_X) ? PLAYER_O : PLAYER_X;
}

void check_row(game_t *game, int i, int px[3], int po[3])
{
    if (memcmp(&game->board[i], px, 3 * sizeof(int)) == 0)
        game->state = X_WON_STATE;
    else if (memcmp(&game->board[i], po, 3 * sizeof(int)) == 0)
        game->state = O_WON_STATE;
}

void check_col(game_t *game, int j, int px[3], int po[3])
{
    int cells[3];
    for (int i = 0; i < 3; i++)
        cells[i] = game->board[i][j];

    if (memcmp(cells, px, 3 * sizeof(int)) == 0)
        game->state = X_WON_STATE;
    else if (memcmp(cells, po, 3 * sizeof(int)) == 0)
        game->state = O_WON_STATE;
}

void check_diagonal_r(game_t *game, int px[3], int po[3])
{
    int cells[3];
    for (int i = 0; i < 3; i++) {
        cells[i] = game->board[i][i];
    }

    if (memcmp(cells, px, 3 * sizeof(int)) == 0)
        game->state = X_WON_STATE;
    else if (memcmp(cells, po, 3 * sizeof(int)) == 0)
        game->state = O_WON_STATE;
}

void check_diagonal_l(game_t *game, int px[3], int po[3])
{
    int cells[3];
    for (int i = 2; i >= 0; i--) {
        cells[i] = game->board[2 - i][i];
    }

    if (memcmp(cells, px, 3 * sizeof(int)) == 0)
        game->state = X_WON_STATE;
    else if (memcmp(cells, po, 3 * sizeof(int)) == 0)
        game->state = O_WON_STATE;
}

void check_win(game_t *game)
{
    int px[3] = {PLAYER_X, PLAYER_X, PLAYER_X};
    int po[3] = {PLAYER_O, PLAYER_O, PLAYER_O};

    int i = 0;
    while (game->state == RUNNING_STATE && i < 3) {
        check_row(game, i, px, po);
        check_col(game, i, px, po);
        check_diagonal_r(game, px, po);
        check_diagonal_l(game, px, po);

        i++;
    }
}

void check_tie(game_t *game)
{
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (is_empty(*game, j, i) == true)
                return;
        }
    }

    game->state = TIE_STATE;
}

void check_state(game_t *game)
{
    check_win(game);
    if (game->state == RUNNING_STATE)
        check_tie(game);
}

void bot(game_t *game)
{
    if (game->state != RUNNING_STATE)
        return;

    int i, j;
    do {
        i = rand() % 3;
        j = rand() % 3;
    }while(is_empty(*game, i, j) == false);

    game->board[i][j] = PLAYER_O;
    switch_player(game);
}

void play(game_t *game)
{
    check_state(game);

    if (game->player == PLAYER_O) {
        bot(game);
    }
}
