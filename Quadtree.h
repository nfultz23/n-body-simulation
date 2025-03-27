#ifndef QUADTREE_H
#define QUADTREE_H

#include <utility>

#include "./entity.h"

class Tile {
public:
	//Store the coordinates for the corners and center
	const std::pair<int, int> topleft, bottomleft, topright, bottomright;
	const std::pair<int, int> center;
	//Store the x and y values for the edges of the tile
	const int top, bottom, left, right;
	//Store the width and height of the tile
	const int width, height;

	//Use an initialization list to set the constant values above
	Tile(int x, int y, int w, int h) :
		topleft(std::pair<int, int>(x, y)),
		bottomleft(std::pair<int, int>(x, y+h)),
		topright(std::pair<int, int>(x+w, y)),
		bottomright(std::pair<int, int>(x+w, y+h)),
		center(std::pair<int, int>(x + w/2, y + h/2)),
		top(y), bottom(y+h), left(x), right(x+w),
		width(w), height(h) {
		//Ensure that the width and height are positive and nonzero
		if (w <= 0) throw "Width cannot be less than or equal to zero";
		if (h <= 0) throw "Height cannot be less than or equal to zero";
	}
};


class QuadNode {
private:
	particle* body;
	Tile field;
	
	double massTotal;
	std::pair<int, int> massCenter;

	QuadNode* NE;
	QuadNode* NW;
	QuadNode* SW;
	QuadNode* SE;
	
	//Updates the total mass and center of mass
	void updateMassInfo() {
		if (this->isLeaf()) {
			this->massTotal = this->body->mass;
			this->massCenter.first = this->body->xpos;
			this->massCenter.second = this->body->ypos;
			return;
		}

		this->massTotal = 0;
		if (this->getNE() != nullptr) this->massTotal += this->getNE()->getMass();
		if (this->getNW() != nullptr) this->massTotal += this->getNW()->getMass();
		if (this->getSW() != nullptr) this->massTotal += this->getSW()->getMass();
		if (this->getSE() != nullptr) this->massTotal += this->getSE()->getMass();

		this->massCenter.first = 0;
		if (this->getNE() != nullptr) {
			QuadNode* NE = this->getNE();
			this->massCenter.first += NE->getField().center.first * ((double)NE->getMass() / this->getMass());
		}
		if (this->getNW() != nullptr) {
			QuadNode* NW = this->getNW();
			this->massCenter.first += NW->getField().center.first * ((double)NW->getMass() / this->getMass());
		}
		if (this->getSW() != nullptr) {
			QuadNode* SW = this->getSW();
			this->massCenter.first += SW->getField().center.first * ((double)SW->getMass() / this->getMass());
		}
		if (this->getSE() != nullptr) {
			QuadNode* SE = this->getSE();
			this->massCenter.first += SE->getField().center.first * ((double)SE->getMass() / this->getMass());
		}

		this->massCenter.second = 0;
		if (this->getNE() != nullptr) {
			QuadNode* NE = this->getNE();
			this->massCenter.second += NE->getField().center.second * ((double)NE->getMass() / this->getMass());
		}
		if (this->getNW() != nullptr) {
			QuadNode* NW = this->getNW();
			this->massCenter.second += NW->getField().center.second * ((double)NW->getMass() / this->getMass());
		}
		if (this->getSW() != nullptr) {
			QuadNode* SW = this->getSW();
			this->massCenter.second += SW->getField().center.second * ((double)SW->getMass() / this->getMass());
		}
		if (this->getSE() != nullptr) {
			QuadNode* SE = this->getSE();
			this->massCenter.second += SE->getField().center.second * ((double)SE->getMass() / this->getMass());
		}

		return;
	}

	int getQuadrant(int x, int y) const {
		//West
		if (x < this->getField().center.first)
		{ if (y < this->getField().center.second) return 2; else return 3; }
		//East
		else
		{ if (y < this->getField().center.second) return 1; else return 4; }
	}

public:
	QuadNode(int x, int y, int w, int h) : field(Tile(x,y,w,h)) {
		this->NE = nullptr;
		this->NW = nullptr;
		this->SW = nullptr;
		this->SE = nullptr;

		this->body = nullptr;
		
		this->massCenter = this->field.center;
		this->massTotal = 0;
	}

	~QuadNode() {
		if (this->NE) delete this->NE;
		if (this->NW) delete this->NW;
		if (this->SW) delete this->SW;
		if (this->SE) delete this->SE;
	}

	//Inserts a body into this node or its children
	void insert(particle* body) {
		if (this->getBody() == nullptr && !this->hasChildren()) this->body = body;
		else if (this->getBody() != nullptr && !this->hasChildren()) {
			//Store references to the particles to be stored
			particle* p1 = this->getBody();
			particle* p2 = body;

			//Empty the connection to the currently stored body
			this->body = nullptr;

			//Determine which quadrant the first particle will belong to
			int p1Quad = this->getQuadrant(p1->xpos, p1->ypos);
			int p2Quad = this->getQuadrant(p2->xpos, p2->ypos);

			//Insert the first particle in to a child node
			if (p1Quad == 1) {
				if (this->getNE() == nullptr)
					this->NE = new QuadNode(
						this->getField().center.first, this->getField().top,
						this->getField().width / 2, this->getField().height / 2
					);
				this->NE->insert(p1);
			}
			else if (p1Quad == 2) {
				if (this->getNW() == nullptr)
					this->NW = new QuadNode(
						this->getField().left, this->getField().top,
						this->getField().width / 2, this->getField().height / 2
					);
				this->NW->insert(p1);
			}
			else if (p1Quad == 3) {
				if (this->getSW() == nullptr)
					this->SW = new QuadNode(
						this->getField().left, this->getField().center.second,
						this->getField().width / 2, this->getField().height / 2
					);
				this->SW->insert(p1);
			}
			else if (p1Quad == 4) {
				if (this->getSE() == nullptr)
					this->SE = new QuadNode(
						this->getField().center.first, this->getField().center.second,
						this->getField().width / 2, this->getField().height / 2
					);
				this->SE->insert(p1);
			}

			//Insert the second particle in to a child node
			if (p2Quad == 1) {
				if (this->getNE() == nullptr)
					this->NE = new QuadNode(
						this->getField().center.first, this->getField().top,
						this->getField().width / 2, this->getField().height / 2
					);
				this->NE->insert(p2);
			}
			else if (p2Quad == 2) {
				if (this->getNW() == nullptr)
					this->NW = new QuadNode(
						this->getField().left, this->getField().top,
						this->getField().width / 2, this->getField().height / 2
					);
				this->NW->insert(p2);
			}
			else if (p2Quad == 3) {
				if (this->getSW() == nullptr)
					this->SW = new QuadNode(
						this->getField().left, this->getField().center.second,
						this->getField().width / 2, this->getField().height / 2
					);
				this->SW->insert(p2);
			}
			else if (p2Quad == 4) {
				if (this->getSE() == nullptr)
					this->SE = new QuadNode(
						this->getField().center.first, this->getField().center.second,
						this->getField().width / 2, this->getField().height / 2
					);
				this->SE->insert(p2);
			}
		}

		this->updateMassInfo();
		return;
	}

	//Checks whether this node has any children or contains a body
	bool isLeaf() const {
		if (!this->hasChildren() && this->getBody() != nullptr) return true;
		return false;
	}

	bool hasChildren() const {
		if (this->getNE() == nullptr &&
			this->getNW() == nullptr &&
			this->getSW() == nullptr &&
			this->getSE() == nullptr)
			return false;
		return true;
	}


	QuadNode* getNE() const { return this->NE; }
	QuadNode* getNW() const { return this->NW; }
	QuadNode* getSW() const { return this->SW; }
	QuadNode* getSE() const { return this->SE; }
	particle* getBody() const { return this->body; }
	std::pair<int, int> getMassCenter() const { return this->massCenter; }
	int getMass() const { return this->massTotal; }
	Tile getField() const { return this->field; }
};


#endif