#ifndef DEF_FORME
#define DEF_FORME

#include "Couleur.hpp"
#include <cmath>

class Forme
{
	protected:
		int _x;
		int _y;
		int _hauteur;
		int _largeur;
		double _orientation;

		Couleur* _couleur;

	public:
		Forme(int x, int y, int h, int l, double o, int r, int v, int b);
		~Forme();
		
		int getX()const;
		int getY()const;
		void setXY(const int x, const int y);

		int getH() const;
		int getL() const;
		void setHL(const int h, const int l);

		double getO() const;
		void setO(const double o);
};

#endif

