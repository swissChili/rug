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
  "    4  4       3   3333 ",
  "   4  4        3   3    ",
  "  4  4         3   3    ",
  " 4  4           3   3   ",
  " 4 455555 4      3   3  ",
  " 4 4      4       3   3 ",
  " 4        4        3  3 ",
  " 4 4      4            1",
  " 4 44444444            1",
  " 4                     1",
  " 44444444             1 ",
  "         1111111111111  "
};


void fromFile(map foo, std::string f)
{
  std::cout << "Reading map file " << f << std::endl;
  std::ifstream in(f);
  std::string file;
  for (int i = 0; std::getline(in, file); ++i)
  {
    if (file.length() != mapWidth - 1)
    {
      std::cerr << "Line has length " << file.length() << " should have length " << mapWidth << '\n';
      throw "wrong line length";
    }
    strcpy(foo[i], file.c_str());
    std::cout << foo[i] << std::endl;
  }
  //return std::make_shared<map>(defaultMap);
}


#endif
