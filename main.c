#include "main.h"
#include "game.h"
#include "utils.h"
#include <SDL/SDL_ttf.h>

SDL_Surface *board = NULL;
SDL_Surface *x_img = NULL;
SDL_Surface *o_img = NULL;
TTF_Font *font = NULL;

void cleanup()
{
    SDL_FreeSurface(board);
    SDL_FreeSurface(x_img);
    SDL_FreeSurface(o_img);
}

void init_assets()
{
    board = IMG_Load("assets/board.png");
    if (board == NULL)
        die();
    x_img = IMG_Load("assets/x.png");
    if (x_img == NULL)
        die();
    o_img = IMG_Load("assets/o.png");
    if (o_img == NULL)
        die();
    font = TTF_OpenFont("assets/font.ttf", FONTSIZE);
}

void handle_mouseevent(SDL_Event event, game_t *game)
{
    int x, y;
    x = event.button.x / 160;
    y = (event.button.y / 130) - 2;
    if (x >= 0 && x <= 2 && y >= 0 && y <= 2 && is_empty(*game, y, x)) {
        if (game->player == PLAYER_X)
            game->board[y][x] = PLAYER_X;
        else
            game->board[y][x] = PLAYER_O;

        switch_player(game);
    }
}

int main()
{
    // Free Memory
    atexit(cleanup);

    // Load SDL
    uint32_t flags = SDL_HWSURFACE | SDL_DOUBLEBUF;
    if (SDL_Init(SDL_INIT_VIDEO) == -1)
        die();

    SDL_Surface *screen = SDL_SetVideoMode(WIDTH, HEIGHT, 0, flags);
    if (screen == NULL)
        die();

    if (TTF_Init() == -1)
        die();

    srand(time(NULL));

    // Load Images
    init_assets();

    // Initialize game
    game_t game;
    load_game(&game);

    // Game Loop
    while (game.state != QUIT_STATE) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    game.state = QUIT_STATE;
                    break;
                case SDL_KEYDOWN:
                    switch (event.key.keysym.sym) {
                        case SDLK_ESCAPE:
                        case SDLK_q:
                            game.state = QUIT_STATE;
                            break;
                        case SDLK_r:
                            load_game(&game);
                        default: {}
                    }
                case SDL_MOUSEBUTTONDOWN:
                    // if (game.state == RUNNING_STATE) {
                    if (game.state == RUNNING_STATE && game.player == PLAYER_X) {
                        handle_mouseevent(event, &game);
                    }
                default: {}
            }
        }
        play(&game);
        draw_game(screen, game);
    }

    SDL_FreeSurface(screen);

    return EXIT_SUCCESS;
}
