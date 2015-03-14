#ifndef DEF_TRIANGLE
#define DEF_TRIANGLE

#include "Mobile.hpp"

class Triangle: public Mobile
{
	public:
		Triangle(int x, int y, int h, int l, double o, int vit, int r, int v, int b);

		void dessine(sf::RenderWindow* window);
};

#endif

