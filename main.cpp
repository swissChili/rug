#include <iostream>

#include "loop.hpp"

int main(int argc, const char *argv[])
{
  map world = { { ' ' } };
  if (argc > 1)
    fromFile(world, argv[1]);
  else
  {
    std::cerr << "No .map file provided" << std::endl;
    return 1;
  }

  char version[] = "v0.1.0";
  std::cout << "rug render engine " << version << std::endl;
  eventLoop(world);

  return 0;
}
