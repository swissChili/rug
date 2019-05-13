#ifndef COLOR_HPP
#define COLOR_HPP

#include "SFML/Graphics.hpp"
#include <memory>
#include "map.hpp"

static sf::Color playerColor(208, 159, 252);

sf::Color chooseColor(char from)
{
  switch (from)
  {
    case '1':  return sf::Color(221, 99, 156);
    case '2':  return sf::Color(132, 221, 99);
    case '3':  return sf::Color(10, 104, 211);
    case '4':  return sf::Color(242, 234, 238);
    case ' ':  return sf::Color(0,0,0, 120);
    default:   return sf::Color(244, 210, 41);
  }
}

void drawCol(sf::RenderWindow *win, int x, int drawStart, int drawEnd, sf::Color color)
{
  // draw a line on the screen at the right coordinate
  sf::Vertex line[] = {
    sf::Vertex(sf::Vector2f(x, drawStart)),
    sf::Vertex(sf::Vector2f(x, drawEnd))
  };
  color.b -= x / win->getSize().x * 2;
  line[0].color = color;
  color.a -= 180;
  line[1].color = color;
  win->draw(line, 2, sf::Lines);
}

#endif
