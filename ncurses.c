#include <curses.h>

void initncurses();

const int cell_cols = 2;
const int cell_lines = 2;

int main(int argc, char *argv[])
{
    int i;

    initncurses();

    // Draw horizontal lines
    for (i = 0; i < LINES; i += cell_lines)
    {
        mvhline(i, 0, ACS_HLINE, COLS);
    }

    // Draw vertical lines
    for (i = 0; i < COLS; i += cell_cols)
    {
        mvvline(0, i, ACS_VLINE, LINES);
    }

    refresh();
    getch();

    endwin();

    return 0;
}

void initncurses()
{
    initscr();
    clear();
    noecho();
    cbreak();
}
