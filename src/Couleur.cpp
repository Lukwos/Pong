#include "Couleur.hpp"

/* Constructeur */

Couleur::Couleur(int r, int v, int b)
	: _rouge(r), _vert(v), _bleu(b)
{

}

/* Accesseurs */

void Couleur::setRVB(int r, int v, int b)
{
	_rouge = r;
	_vert = v;
	_bleu = b;
}

int Couleur::getR()
{
	return _rouge;
}

int Couleur::getV()
{
	return _vert;
}

int Couleur::getB()
{
	return _bleu;
}
