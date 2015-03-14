#include "Cercle.hpp"

/* Constructeur */

Cercle::Cercle(int x, int y, int rad, double o, int vit, int r, int v, int b)
	: Mobile(x, y, 2*rad, 2*rad, o, vit, r, v, b)
{
	// radius = _largeur
}

/* Fonctions */

void Cercle::dessine(sf::RenderWindow* window)
{
	sf::CircleShape cercle(_largeur/2,80);
	cercle.setFillColor(sf::Color(_couleur->getR(), _couleur->getV(), _couleur->getB()));
	cercle.setOutlineThickness(-2);
	cercle.setOutlineColor(sf::Color(255, 255, 255));
	cercle.setPosition(_x, _y);
	window->draw(cercle);

}
