#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <SDL.h>
#include <cstdlib>
#include <algorithm>
#include "./entity.h"
#include "./environment.h"

double charges[5][5] = {
	{ 1,-2, 5, 3,-2},
	{-1, 1, 4,-4, 3},
	{-3, 4, 1, 4, 1},
	{-5, 0, 2, 1, 1},
	{ 0, 0,-3, 4, 1}
};

using std::min;
using std::max;

class particle {
public:
	int xpos;
	int ypos;
	int radius;
	int mass;

	int type;

	double xvel; double yvel;
	double xacc; double yacc;

	int r; int g; int b;

	particle(int x, int y, int r, int type) {
		this->xpos = x;
		this->ypos = y;

		if (type == 0) { this->mass = 10; }
		else if (type == 1) { this->mass = 25; }
		else if (type == 2) { this->mass = 50; }
		else if (type == 3) { this->mass = 15; }
		else if (type == 4) { this->mass = 45; }
		else { this->mass = 30; }

		if (type == 0) { this->radius = 2; }
		else if (type == 1) { this->radius = 3; }
		else if (type == 2) { this->radius = 4; }
		else if (type == 3) { this->radius = 5; }
		else if (type == 4) { this->radius = 6; }
		else { this->radius = 7; }

		this->xvel = 0;
		this->yvel = 0;

		this->xacc = 0;
		this->yacc = 0;

		this->type = type;

		if (type == 0) { this->r = 0xFF; this->g = 0xFF; this->b = 0x00; }
		else if (type == 1) { this->r = 0xFF; this->g = 0x00; this->b = 0xFF; }
		else if (type == 2) { this->r = 0x00; this->g = 0xFF; this->b = 0xFF; }
		else if (type == 3) { this->r = 0xFF; this->g = 0x00; this->b = 0x00; }
		else if (type  == 4) { this->r = 0x00; this->g = 0xFF; this->b = 0x00; }
		else { this->r = 0x00; this->g = 0x00; this->b = 0xFF; }
	}

	void move() {
		this->xvel += this->xacc;
		this->yvel += this->yacc;

		this->xvel = (this->xvel > 0 ? min(100.0, this->xvel) : max(-100.0, this->xvel));
		this->yvel = (this->yvel > 0 ? min(100.0, this->yvel) : max(-100.0, this->yvel));

		this->xpos += (int)this->xvel * 0.5;
		this->ypos += (int)this->yvel * 0.5;

		this->xvel *= 0.8;
		this->yvel *= 0.8;

		this->xacc = 0;
		this->yacc = 0;
	}
};

std::vector<particle> particlelist;

void createParticle(int x, int y, int type) {
	particle newPart(x, y, 3, type);
	particlelist.push_back(newPart);
	return;
}

void updateParticles() {
	printf("updateParticles()\n");

	for (int i = 0; i < particlelist.size(); i++) {
		double xchange = 0;
		double ychange = 0;

		for (int j = 0; j < particlelist.size(); j++) {
			if (i == j) continue;

			int dx = particlelist[j].xpos - particlelist[i].xpos;
			int dy = particlelist[j].ypos - particlelist[i].ypos;

			double dist = sqrt(pow(dx, 2) + pow(dy, 2));

			double angle = atan2(dy, dx);

			double force =
				10 *
				particlelist[i].mass *
				particlelist[j].mass *
				charges[particlelist[i].type][particlelist[j].type] /
				pow(dist, 2);
			force /= particlelist[i].mass;

			if (dist < (particlelist[i].radius + particlelist[j].radius)) continue;

			xchange += force * cos(angle);
			ychange += force * sin(angle);

			/*
			printf("Force on particle (%d, %d) by particle (%d, %d) is %f\n",
				particlelist[i].xpos, particlelist[i].ypos,
				particlelist[j].xpos, particlelist[j].ypos,
				force);
			//*/
		}

		particlelist[i].xacc += xchange;
		particlelist[i].yacc += ychange;
	}

	for (int x = 0; x < particlelist.size(); x++) particlelist[x].move();
	return;
}

void renderParticles(SDL_Renderer* renderer) {
	for (int x = 0; x < particlelist.size(); x++) {
		SDL_SetRenderDrawColor(
			renderer,
			particlelist[x].r,
			particlelist[x].g,
			particlelist[x].b,
			0xFF
		);
		drawCircle(
			renderer,
			particlelist[x].xpos,
			particlelist[x].ypos,
			particlelist[x].radius
		);
	}

	return;
}