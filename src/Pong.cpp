#include "Pong.hpp"

/* Constructeur */

Pong::Pong()
{

}

/* Fonctions */

void Pong::execute()
{

	sf::RenderWindow window(sf::VideoMode(800, 600), "PONG", sf::Style::Titlebar);
	
	// points des joueurs

	int pt1 = 0;
	int pt2 = 0;


	// gestion de la pause et de la fin
	
	int pause = 0;
	int fin = 0;
	int echap = 0;

	//touches
	
	int z = 0;
	int s = 0;
	int up = 0;
	int down = 0;

	//font

	sf::Font font;
	font.loadFromFile("font.ttf");

	while (window.isOpen())
	{
	 
		sf::Event event;
		while (window.pollEvent(event))
		{


			if (event.type == sf::Event::KeyPressed)
			{

				if(event.key.code == sf::Keyboard::Escape)
				{
					echap = 1;
				}
				if((event.key.code == sf::Keyboard::Escape && pause && !fin)||(event.type == sf::Event::Closed))
				{
					window.close();
				}

				if(event.key.code == sf::Keyboard::Space || event.key.code == sf::Keyboard::Escape)
				{
					if(!pause)
						pause = 1;

					else if(pause)
						pause = 0;
				}
				if(event.key.code == sf::Keyboard::Z)
				{
					z = 1;
				}
				if(event.key.code == sf::Keyboard::S)
				{
					s = 1;
				}
				if(event.key.code == sf::Keyboard::Up)
				{
					up = 1;
				}
				if(event.key.code == sf::Keyboard::Down)
				{
					down = 1;
				}
				if(event.key.code == sf::Keyboard::R)
				{
					pt1 = 0;
					pt2 = 0;
					fin = 0;
				}
			}

			if (event.type == sf::Event::KeyReleased)
			{
				if(event.key.code == sf::Keyboard::Z)
				{
					z = 0;
				}
				if(event.key.code == sf::Keyboard::S)
				{
					s = 0;
				}
				if(event.key.code == sf::Keyboard::Up)
				{
					up = 0;
				}
				if(event.key.code == sf::Keyboard::Down)
				{
					down = 0;
				}
				if(event.key.code == sf::Keyboard::Escape)
				{
					echap = 0;
				}

			}
		}

		window.clear(sf::Color(0,50,0));
		
		dessineTout(&window);

		/* score */
		sf::Text score;
		score.setFont(font);			

		std::ostringstream str1;
		str1 << pt1;
		std::ostringstream str2;
		str2 << pt2;

		std::string str = str1.str() + " - " + str2.str();
		score.setString(str);
		score.setCharacterSize(50);
		score.setColor(sf::Color(0, 0, 0));
		score.setPosition(350,270);
		

		/* situation normale */
		
		if(!pause && !fin)
		{
			gereTouches(z, s, up, down);
			deplaceTout();

			for(unsigned int mob=0; mob<_mobiles.size(); mob++)
			{
				
				if(_mobiles[mob]->getX() < -50)
				{
					pt2++;
					_mobiles[mob]->setXY(400,100);
					_mobiles[mob]->setO(30);
					_mobiles[mob]->setV(5);
					_mobiles[mob]->RVB();


				}
				if(_mobiles[mob]->getX()+_mobiles[mob]->getL() > 850)
				{
					pt1++;
					_mobiles[mob]->setXY(400,500);
					_mobiles[mob]->setO(210);
					_mobiles[mob]->setV(5);
					_mobiles[mob]->RVB();
				}
			}

			/* fin du jeu */

			if(pt1==10 || pt2==10)
			{
				fin = 1;
			}

			window.draw(score);
		}	
	
		/* en pause */
		
		if(pause && !fin)
		{
			sf::RectangleShape rectangle(sf::Vector2f(440, 500));
			rectangle.setPosition(180, 50);
			rectangle.setFillColor(sf::Color(125, 125, 125));
			rectangle.setOutlineThickness(-3);
			rectangle.setOutlineColor(sf::Color(250, 250, 250));
			
			window.draw(rectangle);		
			

			sf::Text text;
			text.setFont(font);
			text.setString("PAUSE");
			text.setCharacterSize(50);
			text.setColor(sf::Color(0, 0, 0));
			text.setPosition(310,50);
			

			window.draw(text);

			text.setString("Joueur Bleu\n\n        Z\n        /\\\n        \\/\n        S");
			text.setCharacterSize(30);
			text.setColor(sf::Color(0, 0, 155));
			text.setPosition(200,150);
			
			window.draw(text);
			

			text.setString(" Joueur Rouge\n\n        HAUT\n            /\\\n            \\/\n         BAS");
			text.setCharacterSize(30);
			text.setColor(sf::Color(155, 0, 0));
			text.setPosition(400,150);
			
			window.draw(text);

			
			text.setString("SCORE  :  " + str);
			text.setCharacterSize(30);
			text.setColor(sf::Color(0, 0, 0));
			text.setPosition(300,400);
			
			window.draw(text);
			
			text.setString("  Appuyez sur ECHAP pour QUITTER\nAppuyez sur ESPACE pour REPRENDRE");
			text.setCharacterSize(20);
			text.setColor(sf::Color(0, 0, 0));
			text.setPosition(220,470);
			
			window.draw(text);
		}
		if(fin)
		{
				sf::RectangleShape rectangle(sf::Vector2f(500, 300));
				rectangle.setPosition(150, 150);
				rectangle.setFillColor(sf::Color(125, 125, 125));
				rectangle.setOutlineThickness(-3);
				rectangle.setOutlineColor(sf::Color(250, 250, 250));
			
				window.draw(rectangle);		

				sf::Text text;
				text.setFont(font);
				text.setString("VICTOIRE");
				text.setCharacterSize(100);
				text.setColor(sf::Color(155*int(pt2/10), 0, 155*int(pt1/10)));
				text.setPosition(170,170);
			
				window.draw(text);


				text.setString("  Appuyez sur ECHAP pour QUITTER\nAppuyez sur R pour RECOMMENCER");
				text.setCharacterSize(20);
				text.setColor(sf::Color(0, 0, 0));
				text.setPosition(220,370);
				if(echap)
					window.close();
			
				window.draw(text);
		}



		window.display();
	}
}

void Pong::collision()
{
	
	for(unsigned int mob=0; mob < _mobiles.size(); mob++)
	{
		
		int moX = _mobiles[mob]->getX();
		int moY = _mobiles[mob]->getY();
		int moH = _mobiles[mob]->getH();
		int moL = _mobiles[mob]->getL();
		double moO = _mobiles[mob]->getO();
		int moV = _mobiles[mob]->getV();

		double oldMoO = moO;

		for(unsigned int mur=0; mur < _murs.size(); mur++)
		{

			int muX = _murs[mur]->getX();
			int muY = _murs[mur]->getY();
			int muH = _murs[mur]->getH();
			int muL = _murs[mur]->getL();
			
			if((moX < muX + muL)
			&& (moX + moL > muX) 
			&& (moY < muY + muH)
			&& (moY + moH > muY))
			{
				
				if((moO >= 0)
				&& (moO < 90))
				{

					if(moV <= moX+moL-muX)
					{
						moO = 360 - moO;
					}

					if(moV <= moY+moH-muY)
					{
						moO = 180 - moO;
					}

				}

				else if((moO >= 90)
				&& (moO < 180))
				{
					if(moV <= moY+moH-muY)
					{
						moO = 180 - moO;
					}

					if(moV <= muX+muL-moX)
					{
						moO = 360 - moO;
					}

				}
	
				else if((moO >= 180)
				&& (moO < 270))
				{
					if(moV <= muX+muL-moX)
					{
						moO = 360 - moO;
					}

					if(moV <= muY+muH-moY)
					{
						moO = 180 - moO;
					}
				}

				else if((moO >= 270)
				&&(moO <=359))
				{
					if(moV >= muY+muH-moY)
					{
						moO = 360 - moO;
					}

					if(moV >= moX+moL-muX)
					{
						moO = 180 - moO;
					}

				}
				_mobiles[mob]->setO(oldMoO + 180);
				_mobiles[mob]->deplace();
				_mobiles[mob]->setO(moO + 1); //ajout pour changer d'angle pour eviter les paterns
				_mobiles[mob]->deplace();
				_mobiles[mob]->setV(moV + _murs[mur]->getC());
				_mobiles[mob]->RVB();
				break;

			}
		}
		
		for(unsigned int mur=0; mur < _mobiles.size(); mur++)
		{

			int muX = _mobiles[mur]->getX();
			int muY = _mobiles[mur]->getY();
			int muH = _mobiles[mur]->getH();
			int muL = _mobiles[mur]->getL();

			int muV = _mobiles[mur]->getV();
			
			if((moX < muX + muL)
			&& (moX + moL > muX) 
			&& (moY < muY + muH)
			&& (moY + moH > muY)
			&& (mur != mob))
			{
				
				if((moO >= 0)
				&& (moO < 90))
				{

					if(moV <= moX+moL-muX)
					{
						moO = 360 - moO;
					}

					if(moV <= moY+moH-muY)
					{
						moO = 180 - moO;
					}

				}

				else if((moO >= 90)
				&& (moO < 180))
				{
					if(moV <= moY+moH-muY)
					{
						moO = 180 - moO;
					}

					if(moV <= muX+muL-moX)
					{
						moO = 360 - moO;
					}

				}
	
				else if((moO >= 180)
				&& (moO < 270))
				{
					if(moV <= muX+muL-moX)
					{
						moO = 360 - moO;
					}

					if(moV <= muY+muH-moY)
					{
						moO = 180 - moO;
					}
				}

				else if((moO >= 270)
				&&(moO <=359))
				{
					if(moV >= muY+muH-moY)
					{
						moO = 360 - moO;
					}

					if(moV >= moX+moL-muX)
					{
						moO = 180 - moO;
					}

				}
				
				if(muV < 0)
				{
					_mobiles[mob]->setO(oldMoO + 180);
					_mobiles[mob]->deplace();
					_mobiles[mob]->setO(moO);
					_mobiles[mob]->deplace();
				}
			}
		}
	}
}

/* Gestion des vecteurs */

void Pong::addMur(int x, int y, int h, int l, double o, int c, int r, int v, int b)
{
	Mur* m = new Mur(x, y, h, l, o, c, r, v, b);
	_murs.push_back(m);
}

void Pong::addTriangle(int x, int y, int h, int l, double o, int vit, int r, int v, int b)
{
	Triangle* t = new Triangle(x, y, h, l, o, vit, r, v, b);
	_mobiles.push_back(t);
}

void Pong::addCercle(int x, int y, int rad, double o, int vit, int r, int v, int b)
{
	Cercle* c = new Cercle(x, y, rad, o, vit, r, v, b);
	_mobiles.push_back(c);
}

/* Deplacements */

void Pong::deplaceTout()
{
	for(unsigned int mob=0; mob<_mobiles.size(); mob++)
	{
		collision();
		_mobiles[mob]->deplace();
	}
}

void Pong::deplaceTout(int dx, int dy)
{
	for(unsigned int mob=0; mob<_mobiles.size(); mob++)
	{
		_mobiles[mob]->deplace(dx,dy);
	}
}

/* Dessins */

void Pong::dessineTout(sf::RenderWindow* window)
{
	for(unsigned int mob=0; mob<_mobiles.size(); mob++)
	{
		Triangle * ptrT = dynamic_cast<Triangle*>(_mobiles[mob]);
		Cercle * ptrC = dynamic_cast<Cercle*>(_mobiles[mob]);

		if(ptrT)
			ptrT->dessine(window);
		if(ptrC)
			ptrC->dessine(window);

	}

	for(unsigned int mur=0; mur<_murs.size(); mur++)
	{
		_murs[mur]->dessine(window);
	}
}

/* gestion des touches joueurs */

void Pong::gereTouches(int z, int s, int up, int down)
{

	Triangle * ptr1 = NULL; //pointeur joueur 1
	Triangle * ptr2 = NULL; //pointeur joueur 2
	int i = 0; //distribution des pointeurs
	
	for(unsigned int mob=0; mob<_mobiles.size(); mob++)
	{
		Triangle * ptrT = dynamic_cast<Triangle*>(_mobiles[mob]);

		if(ptrT && i==0)
		{
			ptr1 = ptrT;
			i++;
		}

		else if(ptrT && i==1)
		{
			ptr2 = ptrT;
			i++;
		}
	}

	if(z)
	{
		if(ptr1->getY() > 35)
			ptr1->deplace(0,-12);
	}
	if(s)
	{
		if(ptr1->getY() < 465)
			ptr1->deplace(0,12);
	}
	if(up)
	{
		if(ptr2->getY() > 35)
			ptr2->deplace(0,-12);
	}
	if(down)
	{
		if(ptr2->getY() < 465)
			ptr2->deplace(0,12);
	}
}
