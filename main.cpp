#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "menu.hpp"

int main()
{
  int	a;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Yu Gi Oh");
  sf::Texture texture;
  sf::Text volume;
  sf::Font font;
  sf::CircleShape shape(100.f);
  sf::Music music;


  music.openFromFile("music/yu.ogg");
  music.setVolume(50);

  music.play();

  shape.setFillColor(sf::Color::Green);
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
		      a = 1;
		      std::cout << "Play button has been pressed" << std::endl;
		      break;
		    case 1:
		      a = 2;
		      break;
		    case 2:
		      a = 4;
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
      while (a == 2)
	{
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    {
	      a = 3;
	    }
	  else
	    {
	           sf::CircleShape shape(100.f);
	      shape.setFillColor(sf::Color::Green);
	      //font.loadFromFile("police/airstrike.ttf");
	      // volume.setFont(font);
	      //volume.setColor(sf::Color::Red);
	      //volume.setString("VOLUME");

	      //while (window.isOpen())
	      //{
		  sf::Event event;
		  while (window.pollEvent(event))
		    {
		      if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
			window.close();

		      if (event.type == sf::Event::EventType::KeyPressed){

			if (event.key.code == sf::Keyboard::Key::Down)
			  music.setVolume(music.getVolume() - 10);
			if (event.key.code == sf::Keyboard::Key::Up)
			  music.setVolume(music.getVolume() + 10);

			std::cout << "Current volume is :" << music.getVolume() << std::endl;
		      }

		    }
		  window.clear();
		  window.draw(spr);
		  window.draw(shape);
		  window.display();
		  //}
	      //window.clear();
	      //window.draw(shape);
	      //	      window.draw(spr);
	      /*
	      font.loadFromFile("police/airstrike.ttf");
	      volume.setFont(font);
	      volume.setColor(sf::Color::Red);
	      volume.setString("VOLUME");
	      window.draw(volume);

	      //menu.Draw_options(window);
	      //menu.draw(window);
	      window.display();
	      */
	    }
	}
      if (a == 4)
	{
	  window.close();
	}
      else
	{
	  window.clear();
	  window.draw(spr);
	  menu.draw(window);
	  window.display();
	}
    }
}
