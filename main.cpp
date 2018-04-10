#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include <iostream>
#include "menu.hpp"

using namespace std;

int main()
{
  int	a;
  int	b;
  int	c;
  sf::RenderWindow window(sf::VideoMode(WIDTH, HEIGHT), "Yu Gi Oh");
  sf::Texture texture;
  sf::Text volume;
  sf::Font font;
  sf::Music music;
  sf::Music music1;
  sf::Texture curseur;


  b = 1;
  c = 2;
  curseur.loadFromFile("image/curseur.png");

  sf::Sprite curseur1(curseur);
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
          curseur1.setPosition(sf::Vector2f(700, 495));

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
	      sf::Texture vie_joueur;
	      sf::Texture vie_joueur2;
	      sf::Texture attaque;


	      sf::Texture display1;

	      sf::Texture carte1;
	      sf::Texture carte2;
	      sf::Texture carte3;
	      sf::Texture carte4;
	      sf::Texture carte5;

	      sf::Texture carte6;
	      sf::Texture carte7;
	      sf::Texture carte8;
	      sf::Texture carte9;
	      sf::Texture carte10;

	      //	      sf::Texture curseur;

	      display1.loadFromFile("image/carte_dragon_bleu.png");

	      carte1.loadFromFile("image/yugi_carte2.png");
	      carte2.loadFromFile("image/yugi_carte2.png");
	      carte3.loadFromFile("image/yugi_carte2.png");
	      carte4.loadFromFile("image/yugi_carte2.png");
	      carte5.loadFromFile("image/yugi_carte2.png");

	      carte6.loadFromFile("image/yugi_carte2.png");
	      carte7.loadFromFile("image/yugi_carte2.png");
	      carte8.loadFromFile("image/yugi_carte2.png");
	      carte9.loadFromFile("image/yugi_carte2.png");
	      carte10.loadFromFile("image/yugi_carte2.png");


	      vie_joueur.loadFromFile("image/rect2.png");
	      vie_joueur2.loadFromFile("image/rect.png");

	      //	      curseur.loadFromFile("image/curseur.png");


	      plateau.loadFromFile("image/plateau2.jpg");

	      attaque.loadFromFile("image/plateau.png");


	      sf::Sprite vie1(vie_joueur);
	      sf::Sprite vie2(vie_joueur2);


	      sf::Sprite spr1(plateau);

	      sf::Sprite display_carte(display1);

	      sf::Sprite carte1_yugi(carte1);
	      sf::Sprite carte2_yugi(carte2);
	      sf::Sprite carte3_yugi(carte3);
	      sf::Sprite carte4_yugi(carte4);
	      sf::Sprite carte5_yugi(carte5);

	      sf::Sprite carte6_yugi(carte6);
	      sf::Sprite carte7_yugi(carte7);
	      sf::Sprite carte8_yugi(carte8);
	      sf::Sprite carte9_yugi(carte9);
	      sf::Sprite carte10_yugi(carte10);

	      //	      sf::Sprite curseur1(curseur);


	      sf::Text hp1;
	      sf::Text hp2;

	      font.loadFromFile("police/airstrike.ttf");
	      hp1.setFont(font);
	      hp1.setString("Hp: 8000");
	      hp1.setColor(sf::Color::Blue);
	      hp1.setPosition(50, 50);

	      font.loadFromFile("police/airstrike.ttf");
	      hp2.setFont(font);
	      hp2.setString("Hp: 8000");
	      hp2.setColor(sf::Color::Blue);
	      hp2.setPosition(50, 450);


	      sf::Sprite spr4(attaque);


	      vie1.setPosition(sf::Vector2f(30, 50));
	      vie2.setPosition(sf::Vector2f(30, 450));

	      //	      curseur1.setPosition(sf::Vector2f(635,495));


	      carte1_yugi.setPosition(sf::Vector2f(640, 500));
	      carte2_yugi.setPosition(sf::Vector2f(580, 500));
	      carte3_yugi.setPosition(sf::Vector2f(520, 500));
	      carte4_yugi.setPosition(sf::Vector2f(460, 500));
	      carte5_yugi.setPosition(sf::Vector2f(400, 500));

	      carte6_yugi.setPosition(sf::Vector2f(400, 50));
	      carte7_yugi.setPosition(sf::Vector2f(460, 50));
	      carte8_yugi.setPosition(sf::Vector2f(520, 50));
	      carte9_yugi.setPosition(sf::Vector2f(580, 50));
	      carte10_yugi.setPosition(sf::Vector2f(640, 50));

	      display_carte.setPosition(sf::Vector2f(500, 150));

	      spr4.setPosition(sf::Vector2f(30,150));

		  sf::Event event;
		  while (window.pollEvent(event))
		    {
		      if (event.type == sf::Event::Closed)
			window.close();
		    }

		  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && (b >= 1))
		    {
		      if (b == 1)
			{
			  curseur1.setPosition(sf::Vector2f(633, 495));
			  //			  window.draw(display_carte);
			  //curseur1.move(-15, 0);
			}
		      //		      window.draw(display_carte);

		      //      b++;
		    }
		  else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		    {
		      curseur1.move(15, 0);
		    }


		  //music1.setVolume(50);
		  // music1.play();
		  window.clear();
		  // window.draw(spr);
		  window.draw(spr1);

		  window.draw(curseur1);
		  window.draw(carte1_yugi);
		  window.draw(carte2_yugi);
		  window.draw(carte3_yugi);
		  window.draw(carte4_yugi);
		  window.draw(carte5_yugi);

		  window.draw(carte6_yugi);
		  window.draw(carte7_yugi);
		  window.draw(carte8_yugi);
		  window.draw(carte9_yugi);
		  window.draw(carte10_yugi);

		  window.draw(display_carte);

		  window.draw(vie1);
		  window.draw(vie2);
		  window.draw(hp1);
		  window.draw(hp2);

		  window.draw(spr4);

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
