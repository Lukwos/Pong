#include "Mobile.hpp"
/* Constructeur */ 
	
Mobile::Mobile(int x, int y, int h, int l, double o, int vit, int r, int v, int b)
	: Forme(x, y, h, l, o, r, v, b), _vitesse(vit)
{

}

/* Accesseurs */

int Mobile::getV() const
{
	return _vitesse;
}

void Mobile::setV(const int v)
{
	_vitesse = v;
}

/* Fonctions */

void Mobile::deplace(int dx, int dy)
{
		_x += dx;
		_y += dy;
}

void Mobile::deplace()
{
	if(_vitesse > 0)
	{
		int dx = std::cos(_orientation * M_PI/180) * _vitesse;
		int dy = std::sin(_orientation * M_PI/180) * _vitesse;

		_x += dx;
		_y += dy;
	}
}

void Mobile::RVB() //rafraichir les couleurs en fonction de la vitesse
{
	_couleur->setRVB(12*_vitesse, 255-12*_vitesse, 0);
}
