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
  sf::Music music;
  sf::Music music1;

  //MUSIC//
  music.openFromFile("music/yu.ogg");
  music1.openFromFile("music/yu1.ogg");
  music.setVolume(5);
  music.play();
  //  sound.SetLoop(true);

  // TEXTE OPTION //

  font.loadFromFile("police/airstrike.ttf");
  volume.setFont(font);
  volume.setString("Volume:");
  volume.setColor(sf::Color::Red);
  volume.setPosition(50, 300);


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
		      music1.setVolume(50);
		      music1.play();
		      a = 1;
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
	      a = 10;
	    }
	  else
	    {
	      sf::Texture background;

	      background.loadFromFile("image/option.png");

	      sf::Sprite spr2(background);

		  sf::Event event;
		  while (window.pollEvent(event))
		    {
		      if (event.type == sf::Event::EventType::KeyPressed){

			if (event.key.code == sf::Keyboard::Key::Down)
			  music.setVolume(music.getVolume() - 10);
			if (event.key.code == sf::Keyboard::Key::Up)
			  music.setVolume(music.getVolume() + 10);

			std::cout << "Current volume is :" << music.getVolume() << std::endl;
		      }

		    }
		  window.clear();
		  window.draw(spr2);
		  window.draw(volume);
		  window.display();
	    }
	}
      while (a == 1)
	{
	  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
	    {
	      music1.stop();
	      music.play();
	      a = 10;
	    }
	  else
	    {
	      music.stop();

	      sf::Texture plateau;

	      plateau.loadFromFile("image/yugi.png");
	      sf::Sprite spr1(plateau);

		  sf::Event event;
		  while (window.pollEvent(event))
		    {
		      if (event.type == sf::Event::Closed)
			window.close();
		    }

		  //music1.setVolume(50);
		  // music1.play();
		  window.clear();
		  // window.draw(spr);
		  window.draw(spr1);
		  window.display();
	    }
	}

      if (a == 4)
	{
	  window.close();
	}
      else if (a == 10 || a > 7)
	{
	  window.clear();
	  window.draw(spr);
	  menu.draw(window);
	  window.display();
	}
    }
}
