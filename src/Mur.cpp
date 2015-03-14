#include "Mur.hpp"

/* Constructeur */

Mur::Mur(int x, int y, int h, int l, double o, int c, int r, int v, int b)
	: Forme(x, y, h, l, o, r, v, b), _coefficient(c)
{

}

/* Accesseurs */

int Mur::getC() const
{
	return _coefficient;
}

void Mur::setC(const int c)
{
	_coefficient = c;
}

/* Fonctions */

void Mur::dessine(sf::RenderWindow* window)
{
	sf::RectangleShape rectangle(sf::Vector2f(_largeur, _hauteur));
	rectangle.setFillColor(sf::Color(_couleur->getR(), _couleur->getV(), _couleur->getB()));
	rectangle.setOutlineThickness(-2);
	rectangle.setOutlineColor(sf::Color(255, 255, 255));
	rectangle.setPosition(_x, _y);
	window->draw(rectangle);

}

