#include "Forme.hpp"

/* Constructeur */

Forme::Forme(int x, int y, int h, int l, double o, int r, int v, int b)
	: _x(x), _y(y), _hauteur(l), _largeur(h), _orientation(o), _couleur(new Couleur(r, v, b))
{

}

Forme::~Forme()
{
	delete _couleur;
}

/* Accesseurs XY */

int Forme::getX() const
{
	return _x;
}

int Forme::getY() const
{
	return _y;
}

void Forme::setXY(const int x, const int y)
{
	_x = x;
	_y = y;
}

/* Accesseur Hauteur Largeur */



int Forme::getH() const
{
	return _hauteur;
}

int Forme::getL() const
{
	return _largeur;
}

void Forme::setHL(const int h, const int l)
{
	_hauteur = h;
	_largeur = l;
}

/* Accesseur Orientation */



double Forme::getO() const
{
	return _orientation;
}

void Forme::setO(const double o)
{
	_orientation = o;

	if(_orientation < 0.0)
		_orientation += 360.0;

	if(_orientation >= 360.0)
		_orientation -= 360.0;
}

