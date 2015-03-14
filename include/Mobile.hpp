#ifndef DEF_MOBILE
#define DEF_MOBILE

#include "Forme.hpp"
#include <SFML/Graphics.hpp>
#include <cmath>

class Mobile: public Forme
{
	protected:
		int _vitesse;

	public:
		Mobile(int x, int y, int h, int l, double o, int vit, int r, int v, int b);
		virtual ~Mobile() {};
		void deplace(int dx, int dy);
		void deplace();

		virtual void dessine(sf::RenderWindow* window) = 0;

		void RVB();

		int getV() const;
		void setV(const int v);
};

#endif

