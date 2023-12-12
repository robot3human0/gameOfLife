#include "life.h"

int main() {
    Board board;
    fill(board);

    // do {
    //     rules();
    //     show(board);
    //     step(board);
    //     std::this_thread::sleep_for(std::chrono::milliseconds(270));
    //     system("clear");
    // } while (true);

    char c;
    unsigned milsec = 250;
    while(true) {
        rules();
        show(board);
        step(board);
        std::this_thread::sleep_for(std::chrono::milliseconds(270));
        // system("clear");

        initscr();
        noecho();
        cbreak();
        c = getch();
        if (c == 'q') {
            break;
        } else if (c == '=') {
            milsec += 20;
        } else if (c == '-') {
            milsec -= 20;
        }
        endwin();
    }
    return 0;
}
