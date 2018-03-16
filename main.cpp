#include "SFML/Graphics.hpp"
#include <iostream>
#include "menu.h"

int main()
{
  sf::RenderWindow window(sf::VideoMode(600, 600), "Yu Gi Oh");
  sf::Texture texture;
  texture.loadFromFile("image/screen_Menu.jpg");


  sf::Sprite spr(texture);
  Menu menu(window.getSize().x, window.getSize().y);

  while (window.isOpen())
    {
      sf::Event event;

      while (window.pollEvent(event))
	{
	  switch (event.type)
	    {
	    case sf::Event::KeyReleased:
	      switch (event.key.code)
		{
		case sf::Keyboard::Up:
		  menu.MoveUp();
		  break;

		case sf::Keyboard::Down:
		  menu.MoveDown();
		  break;

		case sf::Keyboard::Return:
		  switch (menu.GetPressedItem())
		    {
		    case 0:
		      std::cout << "Play button has been pressed" << std::endl;
		      break;
		    case 1:
		      std::cout << "Option button has been pressed" << std::endl;
		      break;
		    case 2:
		      window.close();
		      break;
		    }

		  break;
		}

	      break;
	    case sf::Event::Closed:
	      window.close();

	      break;

	    }
	}

      window.clear();

      window.draw(spr);
      menu.draw(window);

      window.display();
    }
}
