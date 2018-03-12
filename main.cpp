#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 #include <SFML/Window.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

int	main()
{
  sf::RenderWindow window(sf::VideoMode(800, 600), "Yu Gi Oh");

  sf::Texture texture;
  texture.loadFromFile("image/screen_Menu.jpg");

  sf::Sprite spr(texture);

  sf::Event event;
  while(window.isOpen())
    {
      while(window.pollEvent(event))
	{
	  if(event.type == sf::Event::Closed)
	    window.close();
	}

      window.clear();
      window.draw(spr);
      window.display();
    }

  return 0;
}
