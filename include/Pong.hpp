#ifndef DEF_PONG
#define DEF_PONG

#include "Mur.hpp"
#include "Mobile.hpp"
#include "Cercle.hpp"
#include "Triangle.hpp"

#include <vector>
#include <sstream>

class Pong
{
	protected:
		std::vector<Mur*> _murs;
		std::vector<Mobile*> _mobiles;

	public:
		Pong();

		void execute();
		void collision();

		void gereTouches(int z, int s, int up, int down);

		void addMur(int x, int y, int h, int l, double o, int c, int r, int v, int b);
		void addTriangle(int x, int y, int h, int l, double o, int vit, int r, int v, int b);
		void addCercle(int x, int y, int rad, double o, int vit, int r, int v, int b);

		void deplaceTout();
		void deplaceTout(int dx, int dy);
		void dessineTout(sf::RenderWindow* window);
};

#endif

