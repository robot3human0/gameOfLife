#include "life.h"

void rules() {
    std::cout << "PRESS \"q\" TO STOP THE GAME\n";
    std::cout << "PRESS \"+\" TO SPEED-UP\n";
    std::cout << "PRESS \"-\" TO SPEED-DOWN\n";
}

void fill(Board board) {
    for (int i = 0; i < __WORLD_HEIGHT__; ++i) {
        for (int j = 0; j < __WORLD_WIDTH__; ++j) {
            char c;
            std::cin >> c; 
            if (c == '0') {
                board[i][j] = 0;
            } else if (c == '1') {
                board[i][j] = 1;
            }
        }
    }
}

void fill_rand(Board board) {
    std::srand(std::time(nullptr));

    for (int i = 0; i < __WORLD_HEIGHT__; ++i) {
        for (int j = 0; j < __WORLD_WIDTH__; ++j) {
            if (rand() % 10 == 0) {
                board[i][j] = 1;
            } else {
                board[i][j] = 0;
            }
        }
    }
}

void showMe(const Board board) {
    for (int i = 0; i < __WORLD_HEIGHT__; ++i) {
        for (int j = 0; j < __WORLD_WIDTH__; ++j) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

void show(const Board board) {
    for (int i = 0; i < __WORLD_HEIGHT__; ++i) {
        std::cout << "\033[42m";
        for (int j = 0; j < __WORLD_WIDTH__; ++j) {
            if (board[i][j]) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
        }
        std::cout << "\033[0m";
        std::cout << std::endl;
    }
}

void copy(Board src, Board dst) {
    for (int i = 0; i < __WORLD_HEIGHT__; ++i) {
        for (int j = 0; j < __WORLD_WIDTH__; ++j) {
            dst[i][j] = src[i][j];
        }
    }
}

void step(Board board) {
    Board prev;
    copy(board, prev);

    for (int i = 0; i < __WORLD_HEIGHT__; ++i) {
        for (int j = 0; j < __WORLD_WIDTH__; ++j) {
            int count_beib = 0;
            count_beib += prev[get_x(i - 1)][get_y(j - 1)];
            count_beib += prev[get_x(i - 1)][get_y(j)];
            count_beib += prev[get_x(i - 1)][get_y(j + 1)];
            count_beib += prev[get_x(i)][get_y(j - 1)];
            count_beib += prev[get_x(i)][get_y(j + 1)];
            count_beib += prev[get_x(i + 1)][get_y(j - 1)];
            count_beib += prev[get_x(i + 1)][get_y(j)];
            count_beib += prev[get_x(i + 1)][get_y(j + 1)];

            if (prev[i][j] == 0 && (count_beib == 3)) {
                board[i][j] = 1;
            } else if ((count_beib < 2) || (count_beib > 3)) {
                board[i][j] = 0;
            }
        }    
    }
}

int get_x(int i) {
    return (__WORLD_HEIGHT__ + i) % __WORLD_HEIGHT__;
}

int get_y(int j) {
    return (__WORLD_WIDTH__ + j) % __WORLD_WIDTH__;
}
