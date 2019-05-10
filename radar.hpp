#ifndef RADAR_HPP
#define RADAR_HPP

#include "SFML/Graphics.hpp"
#include "map.hpp"
#include "render.hpp"

static float tileScale = 10.0;

void radar(sf::RenderWindow *win, double posX, double posY)
{
  for (int i = 0; i < mapHeight; ++i)
  {
    for (int j = 0; j < mapWidth; ++j)
    {
      // Skip EOF and empty cells
      if (worldMap[i][j] != 0)
      {
        sf::Color c = chooseColor(worldMap[i][j]);
        sf::VertexArray box(sf::Quads, 4);
        box[0].position = sf::Vector2f(tileScale * j, tileScale * i);
        box[1].position = sf::Vector2f(tileScale * j, tileScale * i + tileScale);
        box[2].position = sf::Vector2f(tileScale * j + tileScale, tileScale * i + tileScale);
        box[3].position = sf::Vector2f(tileScale * j + tileScale, tileScale * i);
        box[0].color = c;
        box[1].color = c;
        box[2].color = c;
        box[3].color = c;
        win->draw(box);
      }
    }
  }
  sf::CircleShape player(5.f);
  player.setPosition(posY * tileScale - tileScale / 2, posX * tileScale - tileScale / 2);
  player.setFillColor(playerColor);
  win->draw(player);
}

#endif
