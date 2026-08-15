#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <ncurses.h>
#include <iostream>
#include <unistd.h>
#include <cstring>

void draw_ascii(int x, int y) {
    if (y < 26) { // not full card can be displayed 
        return;
    }

    for (int i = 1; i < (y-1);  ++i) {
        mvprintw(i, 2, "|");
    }
    for (int i = 1; i < (y-1);  ++i) {
        mvprintw(i, (x-3), "|");
    }
    for (int i = 2; i < (x-2); ++i) {
        mvprintw(0, i, "#");
    }
    for (int i = 2; i < (x-2); ++i) {
        mvprintw(y-1, i, "#");
    }

    size_t col = 0;
    size_t rows = 0;
    

    for (int i = 3; (i < (y-2)) && (col <= 9); i += 2) {
        for (int j = 4; (j < (x-4)); j += 3) {
            mvprintw(i, j, "%li", col);   
        }
        col++;
    }
    for (int i = 4; i < (x-4); i += 3) {
        mvprintw(24, i, "%li", rows);
        rows++;
    }
}
void draw_ascii(int x, int y, size_t *ptr,  const char ch) {
    // idea is: depending on the character and current position, make some digits blank
    if (ptr == NULL) {
        return;
    }
    if ((y < 26) || (*ptr >= ((size_t)(x-8)))) { // not full card can be displayed 
        return;
    }

    for (int i = 1; i < (y-1);  ++i) {
        mvprintw(i, 2, "|");
    }
    for (int i = 1; i < (y-1);  ++i) {
        mvprintw(i, (x-3), "|");
    }
    for (int i = 2; i < (x-2); ++i) {
        mvprintw(0, i, "#");
    }
    for (int i = 2; i < (x-2); ++i) {
        mvprintw(y-1, i, "#");
    }

    switch (ch) {
        case '0': {
            mvprintw(3, 4+(*ptr)," ");
            break;
        }
        case '1': {
            mvprintw(5, 4+(*ptr)," ");
            break;
        }
        case '2': {
            mvprintw(7, 4+(*ptr)," ");
            break;
        }
        case '3': {
            mvprintw(9, 4+(*ptr)," ");
            break;
        }
        case '4': {
            mvprintw(11, 4+(*ptr)," ");
            break;
        }
        case '5': {
            mvprintw(13, 4+(*ptr)," ");
            break;
        }
        case '6': {
            mvprintw(15, 4+(*ptr)," ");
            break;
        }
        case '7': {
            mvprintw(17, 4+(*ptr)," ");
            break;
        }
        case '8': {
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '9': {
            mvprintw(21, 4+(*ptr)," ");
            break;
        }
        case '#': {
            mvprintw(9, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '\"': {
            mvprintw(17, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '=': {
            mvprintw(15, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '/': {
            mvprintw(3, 4+(*ptr)," ");
            mvprintw(5, 4+(*ptr)," ");
            break;
        }
        case '\'': {
            mvprintw(13, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '@': {
            mvprintw(11, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case ':': {
            mvprintw(7, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '?': {
            mvprintw(3, 4+(*ptr)," ");
            mvprintw(17, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '_': {
            mvprintw(3, 4+(*ptr)," ");
            mvprintw(13, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case '%': {
            mvprintw(3, 4+(*ptr)," ");
            mvprintw(11, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case ',': {
            mvprintw(3, 4+(*ptr)," ");
            mvprintw(9, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        case ' ': {
            mvprintw(3, 4+(*ptr)," ");
            mvprintw(7, 4+(*ptr)," ");
            mvprintw(19, 4+(*ptr)," ");
            break;
        }
        default: {
            return;
        }
    }
    *ptr += 3;
    

}

int main() {
    int x, y;
    size_t ptr = 0;
    char ch;
    WINDOW *stdscr = initscr();
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, y, x);
    draw_ascii(x, y);
    while (true) {
        ch = getch();
        if (static_cast<int>(ch) == 10) {
            FILE *fs = fopen("out.ascii", "w+");
            if (fs == NULL) {
                endwin();
                return 1;
            }
            char temp[2];
            for (int i = 0; i < y; ++i) {
                for (int j = 0; j < x; ++j) {
                    temp[0] = mvinch(i, j);
                    fwrite(temp, sizeof(char), 1, fs);
                }
                temp[0] = '\n';
                fwrite(temp, sizeof(char), 1, fs);
            }
            fclose(fs);
            break;
        }
        draw_ascii(x, y, &ptr, ch);
        refresh();
        sleep(1);
    }

    echo();
    endwin();
    return 0;
}
