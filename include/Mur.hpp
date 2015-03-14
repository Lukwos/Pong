#ifndef DEF_MUR
#define DEF_MUR

#include "Forme.hpp"
#include <SFML/Graphics.hpp>

class Mur: public Forme
{
	protected:
		double _coefficient;
	
	public:
		Mur(int x, int y, int h, int l, double o, int c, int r, int v, int b);

		void dessine(sf::RenderWindow* window);

		int getC() const;
		void setC(const int c);
};

#endif

