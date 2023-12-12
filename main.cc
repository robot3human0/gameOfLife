#include "life.h"

int main() {
    std::string s;
    std::cin >> s;
    std::cout << std::endl;
    Board board;
    // fill(board);
    // fill_rand(board);
    fill_from_file(board, s);
    // show(board);
    // char c;
    // unsigned milsec = 500;

    // do {
    //     rules();
    //     show(board);
    //     step(board);
    //     std::this_thread::sleep_for(std::chrono::milliseconds(270));
    //     system("clear");
    // } while (true);

    // initscr();
    // noecho();
    // timeout(3);

    // while(true) {
    //     rules();
    //     show(board);
    //     step(board);
    //     std::this_thread::sleep_for(std::chrono::milliseconds(milsec));
    //     system("clear");

    //     c = getch();
    //     if (c == 'q') break;
    //     else if (c == '=') milsec += 100;
    //     else if (c == '-') milsec -= 100;
    // }
    // endwin();
    return 0;
}
