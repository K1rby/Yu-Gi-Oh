#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
 #include <SFML/Window.hpp>
#include <cstdlib>
#include <vector>
#include <iostream>

using namespace std;

/*
int	main()
{
  RenderWindow window(VideoMode(800, 600, 32), "Yu-Gi-Oh");
  Texture texture;
  Sprite sprite;
  Image image;

  if (!texture.loadFromFile("image/iron.bmp", sf::IntRect(10, 10, 32, 32)))
    {
      cout << "Erreur durant le chargement de l'image" << endl;
      return EXIT_FAILURE;
    }
  else
    {
      sprite.setTexture(texture);
    }
  while (window.isOpen())
    {
      Event event;

      while (window.waitEvent(event))
	{
	  if (event.type == Event::Closed)
	    window.close();
	}
      window.clear();
      window.draw(sprite);
      window.display();
    }
  return EXIT_SUCCESS;
}
*/
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
