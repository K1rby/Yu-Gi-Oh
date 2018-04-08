#ifndef MENU_H
#define MENU_H

#pragma once
#include "SFML/Graphics.hpp"

#define WIDTH 800
#define HEIGHT 600
#define MAX_NUMBER_OF_ITEMS 3

class Menu
{
 public:
  Menu(float width, float height);

  void	draw(sf::RenderWindow &window);
  void	MoveUp();
  void	MoveDown();
  void	Options();
  void	Draw_options(sf::RenderWindow &window);
  int	GetPressedItem()
  {
    return selectedItemIndex;
  }

 private:
  int		selectedItemIndex;
  sf::Font	font;
  sf::Text	menu[MAX_NUMBER_OF_ITEMS];
  sf::Text	menuText;
  sf::Text	volume;

};

#endif//MENU_H
