#include "Triangle.hpp"

/* Constructeur */

Triangle::Triangle(int x, int y, int h, int l, double o, int vit, int r, int v, int b)
	: Mobile(x, y, h, l, o, vit, r, v, b)
{
	
}

/* Fonctions */

void Triangle::dessine(sf::RenderWindow* window)
{

	sf::ConvexShape triangle;

	triangle.setPointCount(3);
	
	if(_orientation == 0)
	{
	triangle.setPoint(0, sf::Vector2f(_x, _y + _hauteur/2));
	triangle.setPoint(1, sf::Vector2f(_x + _largeur, _y));
	triangle.setPoint(2, sf::Vector2f(_x + _largeur, _y + _hauteur));
	}
	if(_orientation == 180)
	{
	triangle.setPoint(0, sf::Vector2f(_x + _largeur, _y + _hauteur/2));
	triangle.setPoint(1, sf::Vector2f(_x, _y));
	triangle.setPoint(2, sf::Vector2f(_x, _y + _hauteur));
	}

	triangle.setFillColor(sf::Color(_couleur->getR(), _couleur->getV(), _couleur->getB()));
	triangle.setOutlineThickness(-2);
	triangle.setOutlineColor(sf::Color(255, 255, 255));

	window->draw(triangle);
}
