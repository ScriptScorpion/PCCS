#pragma GCC diagnostic ignored "-Wunused-parameter"
#include <ncurses.h>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstring>
#include <string>

#define ROW0 6
#define ROW1 8
#define ROW2 10
#define ROW3 12
#define ROW4 14
#define ROW5 16
#define ROW6 18
#define ROW7 20
#define ROW8 22
#define ROW9 24
#define ROW11 4
#define ROW12 2

void draw_ascii(int x, int y) {
    if (y < 29) { // not full card can be displayed 
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
    
    for (int i = 2; i < 5; i += 2) {
        for (int j = 4; j < (x-4); j += 3) {
            mvprintw(i, j, " ");
        }
    }

    for (int i = 6; (i < (y-2)) && (col <= 9); i += 2) {
        for (int j = 4; j < (x-4); j += 3) {
            mvprintw(i, j, "%li", col);   
        }
        col++;
    }
    for (int i = 4; i < (x-4); i += 3) {
        mvprintw(27, i, "%li", rows);
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
            mvprintw(ROW0, 4+(*ptr)," ");
            break;
        }
        case '1': {
            mvprintw(ROW1, 4+(*ptr)," ");
            break;
        }
        case '2': {
            mvprintw(ROW2, 4+(*ptr)," ");
            break;
        }
        case '3': {
            mvprintw(ROW3, 4+(*ptr)," ");
            break;
        }
        case '4': {
            mvprintw(ROW4, 4+(*ptr)," ");
            break;
        }
        case '5': {
            mvprintw(ROW5, 4+(*ptr)," ");
            break;
        }
        case '6': {
            mvprintw(ROW6, 4+(*ptr)," ");
            break;
        }
        case '7': {
            mvprintw(ROW7, 4+(*ptr)," ");
            break;
        }
        case '8': {
            mvprintw(ROW8, 4+(*ptr)," ");
            break;
        }
        case '9': {
            mvprintw(ROW9, 4+(*ptr)," ");
            break;
        }
        case 'A': {
            mvprintw(ROW1, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'B': {
            mvprintw(ROW2, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'C': {
            mvprintw(ROW3, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'D': {
            mvprintw(ROW4, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'E': {
            mvprintw(ROW5, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'F': {
            mvprintw(ROW6, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'G': {
            mvprintw(ROW7, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'H': {
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'I': {
            mvprintw(ROW9, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case 'J': {
            mvprintw(ROW1, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'K': {
            mvprintw(ROW2, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'L': {
            mvprintw(ROW3, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'M': {
            mvprintw(ROW4, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'N': {
            mvprintw(ROW5, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'O': {
            mvprintw(ROW6, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'P': {
            mvprintw(ROW7, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'Q': {
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'R': {
            mvprintw(ROW9, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case 'S': {
            mvprintw(ROW2, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case 'T': {
            mvprintw(ROW3, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case 'U': {
            mvprintw(ROW4, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case 'V': {
            mvprintw(ROW5, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case 'W': {
            mvprintw(ROW6, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case 'X': {
            mvprintw(ROW7, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case 'Y': {
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case 'Z': {
            mvprintw(ROW9, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case '&': {
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case '.': {
            mvprintw(ROW3, 4+(*ptr), " ");
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW12, 4+(*ptr), "*");
            break;
        }
        case '-': {
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case '$': {
            mvprintw(ROW3, 4+(*ptr), " ");
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case '*': {
            mvprintw(ROW4, 4+(*ptr), " ");
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW11, 4+(*ptr), "*");
            break;
        }
        case '/': {
            mvprintw(ROW1, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case ',': {
            mvprintw(ROW3, 4+(*ptr), " ");
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case '%': {
            mvprintw(ROW4, 4+(*ptr), " ");
            mvprintw(ROW8, 4+(*ptr), " ");
            mvprintw(ROW0, 4+(*ptr), " ");
            break;
        }
        case '#': {
            mvprintw(ROW3, 4+(*ptr), " ");
            mvprintw(ROW8, 4+(*ptr), " ");
            break;
        }
        default: {
            return;
        }
    }
    *ptr += 3;
    

}

int main() {
    size_t card_index = 0;
    std::string filename = "card";
    int x, y;
    size_t ptr = 0;
    char ch;
    WINDOW *stdscr = initscr();
    curs_set(0);
    noecho();
    cbreak();
    keypad(stdscr, TRUE);

    getmaxyx(stdscr, y, x);
    while (true) {
        draw_ascii(x, y);
        while (true) {
            std::this_thread::sleep_for(std::chrono::milliseconds(300));
            ch = getch();
            if (static_cast<int>(ch) == 10) {
                FILE *fs = fopen(std::string(filename + std::to_string(card_index) + ".ascii").c_str(), "w+");
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
                card_index++;
                break;
            }
            else if (static_cast<int>(ch) < 0) {
                break;
            }
            draw_ascii(x, y, &ptr, ch);
            refresh();
        }
        ptr = 0;
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }

    echo();
    endwin();
    return 0;
}
