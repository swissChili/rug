#ifndef KEYS_HPP
#define KEYS_HPP

#include "map.hpp"
#include "SFML/Graphics.hpp"
#include <cmath>

bool handleKeystrokes(
  double *posX, double *posY, double *dirX, double *dirY,
  double *planeX, double *planeY, double fps, map worldMap
)
{

  // exit the game if escape is pressed
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) return true;

  // fps can be a bit shaky, sometimes even overflowing,
  // so i'm using absolute vals
  double moveSpeed = std::abs(floor(fps)) * 0.02;
  double rotSpeed = std::abs(floor(fps)) * 0.015;

  // Move if walls not in the way
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
  {
    if(worldMap[int(*posX + *dirX * moveSpeed)][int(*posY)] == ' ') *posX += *dirX * moveSpeed;
    if(worldMap[int(*posX)][int(*posY + *dirY * moveSpeed)] == ' ') *posY += *dirY * moveSpeed;
  }

  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
  {
    if(worldMap[int(*posX - *dirX * moveSpeed)][int(*posY)] == ' ') *posX -= *dirX * moveSpeed;
    if(worldMap[int(*posX)][int(*posY - *dirY * moveSpeed)] == ' ') *posY -= *dirY * moveSpeed;
  }
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
  {
    double oldDirX = *dirX;
    *dirX = *dirX * cos(-rotSpeed) - *dirY * sin(-rotSpeed);
    *dirY = oldDirX * sin(-rotSpeed) + *dirY * cos(-rotSpeed);
    double oldPlaneX = *planeX;
    *planeX = *planeX * cos(-rotSpeed) - *planeY * sin(-rotSpeed);
    *planeY = oldPlaneX * sin(-rotSpeed) + *planeY * cos(-rotSpeed);
  }
  
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
  {
    // both camera direction and camera plane must be rotated
    double oldDirX = *dirX;
    *dirX = *dirX * cos(rotSpeed) - *dirY * sin(rotSpeed);
    *dirY = oldDirX * sin(rotSpeed) + *dirY * cos(rotSpeed);
    double oldPlaneX = *planeX;
    *planeX = *planeX * cos(rotSpeed) - *planeY * sin(rotSpeed);
    *planeY = oldPlaneX * sin(rotSpeed) + *planeY * cos(rotSpeed);
  }
  return false;
}

#endif
