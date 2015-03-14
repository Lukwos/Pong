#ifndef DEF_COULEUR
#define DEF_COULEUR

class Couleur
{
	protected:
		int _rouge;
		int _vert;
		int _bleu;

	public:
		Couleur(int r, int v, int b);

		void setRVB(int r, int v, int b);
		
		int getR();
		int getV();
		int getB();
};

#endif

