#include "menu.hpp"
#include <iostream>


Menu::Menu(float width, float height)
{
  font.loadFromFile("police/airstrike.ttf");

  menu[0].setFont(font);
  menu[0].setColor(sf::Color::Red);
  menu[0].setString("Play");
  menu[0].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 0.85));

  menu[1].setFont(font);
  menu[1].setColor(sf::Color::White);
  menu[1].setString("Options");
  menu[1].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 1.85));

  menu[2].setFont(font);
  menu[2].setColor(sf::Color::White);
  menu[2].setString("Exit");
  menu[2].setPosition(sf::Vector2f(width / 5, height / (MAX_NUMBER_OF_ITEMS + 1) * 2.85));

  selectedItemIndex = 0;
}

void Menu::draw(sf::RenderWindow &window)
{
  for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
    {
      window.draw(menu[i]);
    }
}

void Menu::MoveUp()
{
  if (selectedItemIndex - 1 >= 0)
    {
      menu[selectedItemIndex].setColor(sf::Color::White);
      selectedItemIndex--;
      menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void Menu::MoveDown()
{
  if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
    {
      menu[selectedItemIndex].setColor(sf::Color::White);
      selectedItemIndex++;
      menu[selectedItemIndex].setColor(sf::Color::Red);
    }
}

void	Menu::Draw_options(sf::RenderWindow &window)
{
  window.draw(volume);
}

void	Menu::Options()
{
  font.loadFromFile("police/airstrike.ttf");
  volume.setFont(font);
  volume.setColor(sf::Color::Red);
  volume.setString("VOLUME");
}
