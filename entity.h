#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <fstream>

class particle {
public:
	int xpos, ypos;
	int radius, mass;
	int type;

	double xvel, yvel;
	double xacc, yacc;

	int r, g, b;

	particle(int, int, int, int);
	void move();
};

void createParticle(int, int, int);
void updateParticles();
void renderParticles(SDL_Renderer* renderer);


#endif