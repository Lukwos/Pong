#ifndef DEF_CERCLE
#define DEF_CERCLE

#include "Mobile.hpp"

class Cercle: public Mobile
{
	public:
		Cercle(int x, int y, int rad, double o, int vit, int r, int v, int b);

		void dessine(sf::RenderWindow* window);
};

#endif

