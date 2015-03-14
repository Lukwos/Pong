#include "Pong.hpp"
#include "Triangle.hpp"

#include <iostream>
#include <SFML/Graphics.hpp>


int main()
{

	Pong pong;


	// balle
	
	pong.addCercle(300,100, 15, 30.0, 5, 0,255,0);

	//joueurs
	
	pong.addTriangle(10,275, 50,100, 0.0, -1, 0,0,155);
	pong.addTriangle(740,275, 50,100, 180.0, -1, 155,0,0);

	for(int i=0; i<50; i++)
	{
		pong.addMur(50*i,0,50,30,0.0,1,int(i*(255/15)),0,255-int(i*(255/15))); //haut
		pong.addMur(50*i,570,50,30,0.0,1,int(i*(255/15)),0,255-int(i*(255/15))); //bas
	}
	pong.addMur(325,250,150,100,0.0,1,125,125,125); //centre

	pong.execute();

	return 0;
}

