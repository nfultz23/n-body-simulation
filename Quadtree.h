#ifndef QUADTREE_H
#define QUADTREE_H

#include <utility>

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

#endif