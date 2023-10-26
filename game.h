#ifndef GAME_H_
#define GAME_H_

#define N 3

#define PLAYER_X 1
#define PLAYER_O 2

enum {
    RUNNING_STATE,
    X_WON_STATE,
    O_WON_STATE,
    TIE_STATE,
    QUIT_STATE,
};

typedef struct {
    int board[N][N];
    int player;
    int state;
}game_t;

#endif // !GAME_H_
