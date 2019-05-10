#ifndef LOOP_HPP
#define LOOP_HPP

#include "map.hpp"
#include "keys.hpp"
#include "render.hpp"
#include "radar.hpp"

#include "SFML/Graphics.hpp"

void eventLoop(map gameMap)
{
  double posX = 22, posY = 12;
  double dirX = -1, dirY = 0;
  double planeX = 0, planeY = 0.66;

  sf::Clock clock;
  double lastTime = 0;

  sf::ContextSettings settings;
  settings.antialiasingLevel = 0;

  sf::RenderWindow window(sf::VideoMode(1920, 1080), "rug", sf::Style::Default, settings);
  sf::RenderWindow *win = &window;

  while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
      if (event.type == sf::Event::Closed) window.close();

    // window dimentions
    int w = window.getSize().x;
    int h = window.getSize().y;

    // index of current map cell
    int mapX = int(posX);
    int mapY = int(posY);

    window.clear(sf::Color::Black);

    for(int x = 0; x < w; x++)
    {
      // ray dir and pos
      double cameraX = 2 * x / double(w) - 1;
      double rayDirX = dirX + planeX * cameraX;
      double rayDirY = dirY + planeY * cameraX;

      // current map cell
      mapX = int(posX);
      mapY = int(posY);

      // length to next x, y
      double sideDistX;
      double sideDistY;

      // length of ray in x, y
      double deltaDistX = std::abs(1 / rayDirX);
      double deltaDistY = std::abs(1 / rayDirY);
      // distance from camera plane
      double camPlaneWallD;

      // direction needed to step in
      int stepX;
      int stepY;

      int side;

      if (rayDirX < 0)
      {
        stepX = -1;
        sideDistX = (posX - mapX) * deltaDistX;
      }
      else
      {
        stepX = 1;
        sideDistX = (mapX + 1.f - posX) * deltaDistX;
      }

      if (rayDirY < 0)
      {
        stepY = -1;
        sideDistY = (posY - mapY) * deltaDistY;
      }
      else
      {
        stepY = 1;
        sideDistY = (mapY + 1.f - posY) * deltaDistY;
      }

      bool hasHit = false;

      while (!hasHit)
      {
        // Check next square
        if (sideDistX < sideDistY)
        {
          sideDistX += deltaDistX;
          mapX += stepX;
          side = 0;
        }
        else
        {
          sideDistY += deltaDistY;
          mapY += stepY;
          side = 1;
        }
        // ' ' is empty, anything else is a wall.
        if (gameMap[mapX][mapY] != ' ')
          hasHit = true;
      }

      // wall distance in relation to camera plane
      // euclidean distance gives fish eye effect.
      if (!side)
        camPlaneWallD = (mapX - posX + (1 - stepX) / 2) / rayDirX;
      else
        camPlaneWallD = (mapY - posY + (1 - stepY) / 2) / rayDirY;

      // size of the col on the screen
      int lineHeight = (int)(h / camPlaneWallD);

      // highest pixel to draw
      int drawStart = -lineHeight / 2 + h / 2;
      if (drawStart < 0)
        drawStart = 0;
      // lowest pixel to draw
      int drawEnd = lineHeight / 2 + h / 2;
      if (drawEnd >= h)
        drawEnd = h - 1;


      sf::Color color = chooseColor(gameMap[mapX][mapY]);

      // set 2 of the sides of the box to a darker color
      if (side == 1) color.a -= 60;

      drawCol(win, x, drawStart, drawEnd, color);
    }

    // render a minimap/radar to the screen
    radar(gameMap, win, posX, posY);

    double currentTime = clock.restart().asSeconds();
    double fps = currentTime - lastTime;

    #ifdef DEBUG
    std::cout << floor(1.f /fps) << " FPS\n";
    #endif

    lastTime = currentTime;

    window.display();

    if (handleKeystrokes(&posX, &posY, &dirX, &dirY, &planeX, &planeY, fps, gameMap))
      window.close();
  }
}

#endif
