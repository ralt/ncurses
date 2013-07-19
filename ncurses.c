#include <curses.h>
#include <stdlib.h>

typedef struct Win
{
    WINDOW *win;
    int x;
    int y;
} Win;

void initncurses();
Win *create_win(const int y, const int x);
Win *create_win_struct(WINDOW *win, int y, int x);
void cleanup_wins(Win *wins[COLS][LINES]);

const int cell_cols = 1;
const int cell_lines = 1;

int main(int argc, char *argv[])
{
    int i, j;
    Win *wins[COLS][LINES];

    initncurses();

    for (i = 0; i < LINES; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            wins[i][j] = create_win(i, j);
        }
    }

    wgetch(wins[0][0]->win);
    endwin();
    cleanup_wins(wins);

    return 0;
}

void initncurses()
{
    initscr();
    clear();
    noecho();
    cbreak();
}

Win *create_win(const int y, const int x)
{
    WINDOW *local_win;

    local_win = newwin(cell_lines, cell_cols, y, x);
    box(local_win, 0, 0);
    wrefresh(local_win);

    return create_win_struct(local_win, y, x);
}

Win *create_win_struct(WINDOW *win, int y, int x)
{
    Win *win_struct = malloc(sizeof(Win));

    win_struct->win = win;
    win_struct->x = x;
    win_struct->y = y;

    return win_struct;
}

void cleanup_wins(Win *wins[COLS][LINES])
{
    int i, j;

    for (i = 0; i < LINES; i++)
    {
        for (j = 0; j < COLS; j++)
        {
            delwin(wins[i][j]->win);
            free(wins[i][j]);
        }
    }
}
