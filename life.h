#ifndef LIFE_H
#define LIFE_H

#include <string>

const int __WORLD_WIDTH__ = 80;
const int __WORLD_HEIGHT__ = 25;

using Board = int[__WORLD_HEIGHT__][__WORLD_WIDTH__];

void rules();
void fill(Board board);
void fill_from_file(Board board, const std::string& pathToFile);
void fill_rand(Board board);
void show(const Board board);
void showMe(const Board board);
void step(Board board);
void copy(Board src, Board dst);
int get_x(int i);
int get_y(int j);

#endif  // LIFE_H
