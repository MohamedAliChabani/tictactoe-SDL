#include "drawing.h"
#include "game.h"
#include "utils.h"

extern SDL_Surface *board;
extern SDL_Surface *x_img;
extern SDL_Surface *o_img;
extern TTF_Font *font;

void draw_board(SDL_Surface *screen, const game_t game)
{
    draw_image(screen, board, 0, 0);
    uint xpos_on_screen, ypos_on_screen;

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            xpos_on_screen = 40 + (130 * j);
            ypos_on_screen = 265 + (133 * i);

            switch (game.board[i][j]) {
                case 1:
                    draw_image(screen, x_img, xpos_on_screen, ypos_on_screen);
                    break;
                case 2:
                    draw_image(screen, o_img, xpos_on_screen, ypos_on_screen);
                    break;
                default: {}
            }
        }
    }
}

void draw_game(SDL_Surface *screen, const game_t game)
{
    SDL_FillRect(screen, NULL, 0);
    draw_board(screen, game);

    SDL_Color color;

    switch (game.state) {
        case X_WON_STATE:
            color.r = 0; color.g = 255; color.b = 0;
            render_text(screen, font, "YOU WON", color, 40, 20);
            break;
        case O_WON_STATE:
            color.r = 255; color.g = 0; color.b = 0;
            render_text(screen, font, "YOU LOST", color, 40, 20);
            break;
        case TIE_STATE:
            color.r = 0; color.g = 0; color.b = 255;
            render_text(screen, font, "TIE", color, 40, 20);
            break;
        default: {
            color.r = 255; color.g = 255; color.b = 255;
            render_text(screen, font, "R: Replay", color, 50, 740);
        }
    }

    SDL_Flip(screen);
    SDL_Delay(60);
}
