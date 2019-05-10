#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include <cstring>
#include <istream>
#include <fstream>
#include <memory>
#include <iostream>

#define mapWidth 25
#define mapHeight 25

typedef char map[mapWidth][mapHeight];

map defaultMap =
{
  "111111111111111111111111",
  "1                      1",
  "1                      1",
  "1                      1",
  " 222  22222    333333331",
  "2         2  3         1",
  "2   55    2  3 3 3 3 3 1",
  "2         2  3         1",
  " 2222222  2  3 3 3 3 3 1",
  "       4  4  3         1",
  "      4  4    33 3 3 3 1",
  "     4  4      3       1",
  "    4  4       3   33331",
  "   4  4        3   3   1",
  "  4  4         3   3   1",
  " 4  4           3   3  1",
  " 4 455555 4      3   331",
  " 4 4      4       3   31",
  " 4        4        3  31",
  " 4 4      4            1",
  " 4 44444444            1",
  " 4                     1",
  " 44444444             1 ",
  "         1111111111111  "
};

#define worldMap defaultMap

#endif
