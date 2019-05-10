#include <iostream>

#include "loop.hpp"

int main()
{
  char version[] = "v0.1.0";
  std::cout << "rug render engine " << version << std::endl;
  eventLoop();
}
