#include "life_otus.h"

int main() {
    Board board;
    fill(board);

    do {
        rules();
        show(board);
        step(board);
        std::this_thread::sleep_for(std::chrono::milliseconds(270));
        system("clear");
    } while (true);
    return 0;
}
