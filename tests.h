#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>
#include <cstdint>

#include "./Quadtree.h"
#include "./entity.h"

using std::to_string;

bool testTileClass() {
	std::cout << "Testing Tile Class:" << std::endl;

	bool passed = true;

	std::cout << "T1 - 100x100 tile at (0,0): ";
	try {
		//Create a tile for testing a square tile at position (0,0) and width 100
		Tile t(0, 0, 100, 100);

		//Ensure the top-left is at (0,0)
		if (t.topleft.first != 0 || t.topleft.second != 0) {
			std::string err = "Tile.topleft values incorrect\n";
			err += "  Template: (0, 0)\n";
			err += "  Response: (" + std::to_string(t.topleft.first);
			err += ", " + std::to_string(t.topleft.second) + ")";

			throw err;
		}

		//Ensure the top-right is at (100,0)
		if (t.topright.first != 100 || t.topright.second != 0) {
			std::string err = "Tile.topright values incorrect\n";
			err += "  Template: (100, 0)\n";
			err += "  Response: (" + std::to_string(t.topright.first);
			err += ", " + std::to_string(t.topright.second) + ")";

			throw err;
		}

		//Ensure the bottom-left is at (0,100)
		if (t.bottomleft.first != 0 || t.bottomleft.second != 100) {
			std::string err = "Tile.bottomleft values incorrect\n";
			err += "  Template: (0, 100)\n";
			err += "  Response: (" + std::to_string(t.bottomleft.first);
			err += ", " + std::to_string(t.bottomleft.second) + ")";

			throw err;
		}

		//Ensure the bottom-right is at (100,100)
		if (t.bottomright.first != 100 || t.bottomright.second != 100) {
			std::string err = "Tile.bottomright values incorrect\n";
			err += "  Template: (100, 100)\n";
			err += "  Response: (" + std::to_string(t.bottomright.first);
			err += ", " + std::to_string(t.bottomright.second) + ")";

			throw err;
		}

		//Ensure the center is at (50,50)
		if (t.center.first != 50 || t.center.second != 50) {
			std::string err = "Tile.center values incorrect\n";
			err += "  Template: (50, 50)\n";
			err += "  Response: (" + std::to_string(t.center.first);
			err += ", " + std::to_string(t.center.second) + ")";

			throw err;
		}

		//Ensure the top is at 0
		if (t.top != 0)
			throw "Tile.top value incorrect\n  Template: 0\n  Response: " +
			std::to_string(t.left);

		//Ensure the bottom is at 100
		if (t.bottom != 100)
			throw "Tile.bottom value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.bottom);

		//Ensure the left is at 0
		if (t.left != 0)
			throw "Tile.left value incorrect\n  Template: 0\n  Response: " +
			std::to_string(t.left);

		//Ensure the right is at 100
		if (t.right != 100)
			throw "Tile.right value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.right);

		//Ensure the width is 100
		if (t.width != 100)
			throw "Tile.width value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.width);

		//Ensure the height is 100
		if (t.height != 100)
			throw "Tile.height value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.height);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}

	std::cout << "T2 - 100x100 tile at (10,10): ";
	try {
		//Create a tile for testing a square tile at position (10,10) and width 100
		Tile t(10, 10, 100, 100);

		//Ensure the top-left is at (10,10)
		if (t.topleft.first != 10 || t.topleft.second != 10) {
			std::string err = "Tile.topleft values incorrect\n";
			err += "  Template: (10, 10)\n";
			err += "  Response: (" + std::to_string(t.topleft.first);
			err += ", " + std::to_string(t.topleft.second) + ")";

			throw err;
		}

		//Ensure the top-right is at (110,10)
		if (t.topright.first != 110 || t.topright.second != 10) {
			std::string err = "Tile.topright values incorrect\n";
			err += "  Template: (110, 10)\n";
			err += "  Response: (" + std::to_string(t.topright.first);
			err += ", " + std::to_string(t.topright.second) + ")";

			throw err;
		}

		//Ensure the bottom-left is at (10,110)
		if (t.bottomleft.first != 10 || t.bottomleft.second != 110) {
			std::string err = "Tile.bottomleft values incorrect\n";
			err += "  Template: (1, 110)\n";
			err += "  Response: (" + std::to_string(t.bottomleft.first);
			err += ", " + std::to_string(t.bottomleft.second) + ")";

			throw err;
		}

		//Ensure the bottom-right is at (110,110)
		if (t.bottomright.first != 110 || t.bottomright.second != 110) {
			std::string err = "Tile.bottomright values incorrect\n";
			err += "  Template: (110, 110)\n";
			err += "  Response: (" + std::to_string(t.bottomright.first);
			err += ", " + std::to_string(t.bottomright.second) + ")";

			throw err;
		}

		//Ensure the center is at (60,60)
		if (t.center.first != 60 || t.center.second != 60) {
			std::string err = "Tile.center values incorrect\n";
			err += "  Template: (60, 60)\n";
			err += "  Response: (" + std::to_string(t.center.first);
			err += ", " + std::to_string(t.center.second) + ")";

			throw err;
		}

		//Ensure the top is at 10
		if (t.top != 10)
			throw "Tile.top value incorrect\n  Template: 10\n  Response: " +
			std::to_string(t.left);

		//Ensure the bottom is at 110
		if (t.bottom != 110)
			throw "Tile.bottom value incorrect\n  Template: 110\n  Response: " +
			std::to_string(t.bottom);

		//Ensure the left is at 10
		if (t.left != 10)
			throw "Tile.left value incorrect\n  Template: 10\n  Response: " +
			std::to_string(t.left);

		//Ensure the right is at 110
		if (t.right != 110)
			throw "Tile.right value incorrect\n  Template: 110\n  Response: " +
			std::to_string(t.right);

		//Ensure the width is 110
		if (t.width != 100)
			throw "Tile.width value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.width);

		//Ensure the height is 110
		if (t.height != 100)
			throw "Tile.height value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.height);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}

	std::cout << "T3 - 100x100 tile at (-10,-10): ";
	try {
		//Create a tile for testing a square tile at position (10,10) and width 100
		Tile t(-10, -10, 100, 100);

		//Ensure the top-left is at (-10,-10)
		if (t.topleft.first != -10 || t.topleft.second != -10) {
			std::string err = "Tile.topleft values incorrect\n";
			err += "  Template: (10, 10)\n";
			err += "  Response: (" + std::to_string(t.topleft.first);
			err += ", " + std::to_string(t.topleft.second) + ")";

			throw err;
		}

		//Ensure the top-right is at (90,-10)
		if (t.topright.first != 90 || t.topright.second != -10) {
			std::string err = "Tile.topright values incorrect\n";
			err += "  Template: (90, -10)\n";
			err += "  Response: (" + std::to_string(t.topright.first);
			err += ", " + std::to_string(t.topright.second) + ")";

			throw err;
		}

		//Ensure the bottom-left is at (-10,90)
		if (t.bottomleft.first != -10 || t.bottomleft.second != 90) {
			std::string err = "Tile.bottomleft values incorrect\n";
			err += "  Template: (-10, 90)\n";
			err += "  Response: (" + std::to_string(t.bottomleft.first);
			err += ", " + std::to_string(t.bottomleft.second) + ")";

			throw err;
		}

		//Ensure the bottom-right is at (90,90)
		if (t.bottomright.first != 90 || t.bottomright.second != 90) {
			std::string err = "Tile.bottomright values incorrect\n";
			err += "  Template: (90, 90)\n";
			err += "  Response: (" + std::to_string(t.bottomright.first);
			err += ", " + std::to_string(t.bottomright.second) + ")";

			throw err;
		}

		//Ensure the center is at (40,40)
		if (t.center.first != 40 || t.center.second != 40) {
			std::string err = "Tile.center values incorrect\n";
			err += "  Template: (40, 40)\n";
			err += "  Response: (" + std::to_string(t.center.first);
			err += ", " + std::to_string(t.center.second) + ")";

			throw err;
		}

		//Ensure the top is at -10
		if (t.top != -10)
			throw "Tile.top value incorrect\n  Template: -10\n  Response: " +
			std::to_string(t.left);

		//Ensure the bottom is at 90
		if (t.bottom != 90)
			throw "Tile.bottom value incorrect\n  Template: 90\n  Response: " +
			std::to_string(t.bottom);

		//Ensure the left is at -10
		if (t.left != -10)
			throw "Tile.left value incorrect\n  Template: -10\n  Response: " +
			std::to_string(t.left);

		//Ensure the right is at 90
		if (t.right != 90)
			throw "Tile.right value incorrect\n  Template: 90\n  Response: " +
			std::to_string(t.right);

		//Ensure the width is 90
		if (t.width != 100)
			throw "Tile.width value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.width);

		//Ensure the height is 90
		if (t.height != 100)
			throw "Tile.height value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.height);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}

	std::cout << "T4 - 100x75 tile at (0,0): ";
	try {
		//Create a rectangular tile with size 100x75 at (0,0)
		Tile t(0, 0, 100, 75);

		//Ensure the top-left is at (0,0)
		if (t.topleft.first != 0 || t.topleft.second != 0) {
			std::string err = "Tile.topleft values incorrect\n";
			err += "  Template: (0, 0)\n";
			err += "  Response: (" + std::to_string(t.topleft.first);
			err += ", " + std::to_string(t.topleft.second) + ")";

			throw err;
		}

		//Ensure the top-right is at (100,0)
		if (t.topright.first != 100 || t.topright.second != 0) {
			std::string err = "Tile.topright values incorrect\n";
			err += "  Template: (100, 0)\n";
			err += "  Response: (" + std::to_string(t.topright.first);
			err += ", " + std::to_string(t.topright.second) + ")";

			throw err;
		}

		//Ensure the bottom-left is at (0,75)
		if (t.bottomleft.first != 0 || t.bottomleft.second != 75) {
			std::string err = "Tile.bottomleft values incorrect\n";
			err += "  Template: (0, 75)\n";
			err += "  Response: (" + std::to_string(t.bottomleft.first);
			err += ", " + std::to_string(t.bottomleft.second) + ")";

			throw err;
		}

		//Ensure the bottom-right is at (100,75)
		if (t.bottomright.first != 100 || t.bottomright.second != 75) {
			std::string err = "Tile.bottomright values incorrect\n";
			err += "  Template: (100, 75)\n";
			err += "  Response: (" + std::to_string(t.bottomright.first);
			err += ", " + std::to_string(t.bottomright.second) + ")";

			throw err;
		}

		//Ensure the center is at (50,37)
		if (t.center.first != 50 || t.center.second != 37) {
			std::string err = "Tile.center values incorrect\n";
			err += "  Template: (50, 37)\n";
			err += "  Response: (" + std::to_string(t.center.first);
			err += ", " + std::to_string(t.center.second) + ")";

			throw err;
		}

		//Ensure the top is at 0
		if (t.top != 0)
			throw "Tile.top value incorrect\n  Template: 0\n  Response: " +
			std::to_string(t.left);

		//Ensure the bottom is at 100
		if (t.bottom != 75)
			throw "Tile.bottom value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.bottom);

		//Ensure the left is at 0
		if (t.left != 0)
			throw "Tile.left value incorrect\n  Template: 0\n  Response: " +
			std::to_string(t.left);

		//Ensure the right is at 100
		if (t.right != 100)
			throw "Tile.right value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.right);

		//Ensure the width is 100
		if (t.width != 100)
			throw "Tile.width value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.width);

		//Ensure the height is 100
		if (t.height != 75)
			throw "Tile.height value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.height);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}

	std::cout << "T5 - 100x75 tile at (10,10): ";
	try {
		//Create a rectangular tile at (10,10) with size 100x75
		Tile t(10, 10, 100, 75);

		//Ensure the top-left is at (10,10)
		if (t.topleft.first != 10 || t.topleft.second != 10) {
			std::string err = "Tile.topleft values incorrect\n";
			err += "  Template: (10, 10)\n";
			err += "  Response: (" + std::to_string(t.topleft.first);
			err += ", " + std::to_string(t.topleft.second) + ")";

			throw err;
		}

		//Ensure the top-right is at (110,10)
		if (t.topright.first != 110 || t.topright.second != 10) {
			std::string err = "Tile.topright values incorrect\n";
			err += "  Template: (110, 10)\n";
			err += "  Response: (" + std::to_string(t.topright.first);
			err += ", " + std::to_string(t.topright.second) + ")";

			throw err;
		}

		//Ensure the bottom-left is at (10,85)
		if (t.bottomleft.first != 10 || t.bottomleft.second != 85) {
			std::string err = "Tile.bottomleft values incorrect\n";
			err += "  Template: (1, 85)\n";
			err += "  Response: (" + std::to_string(t.bottomleft.first);
			err += ", " + std::to_string(t.bottomleft.second) + ")";

			throw err;
		}

		//Ensure the bottom-right is at (110,85)
		if (t.bottomright.first != 110 || t.bottomright.second != 85) {
			std::string err = "Tile.bottomright values incorrect\n";
			err += "  Template: (110, 85)\n";
			err += "  Response: (" + std::to_string(t.bottomright.first);
			err += ", " + std::to_string(t.bottomright.second) + ")";

			throw err;
		}

		//Ensure the center is at (60,47)
		if (t.center.first != 60 || t.center.second != 47) {
			std::string err = "Tile.center values incorrect\n";
			err += "  Template: (60, 47)\n";
			err += "  Response: (" + std::to_string(t.center.first);
			err += ", " + std::to_string(t.center.second) + ")";

			throw err;
		}

		//Ensure the top is at 10
		if (t.top != 10)
			throw "Tile.top value incorrect\n  Template: 10\n  Response: " +
			std::to_string(t.left);

		//Ensure the bottom is at 110
		if (t.bottom != 85)
			throw "Tile.bottom value incorrect\n  Template: 85\n  Response: " +
			std::to_string(t.bottom);

		//Ensure the left is at 10
		if (t.left != 10)
			throw "Tile.left value incorrect\n  Template: 10\n  Response: " +
			std::to_string(t.left);

		//Ensure the right is at 110
		if (t.right != 110)
			throw "Tile.right value incorrect\n  Template: 110\n  Response: " +
			std::to_string(t.right);

		//Ensure the width is 110
		if (t.width != 100)
			throw "Tile.width value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.width);

		//Ensure the height is 110
		if (t.height != 75)
			throw "Tile.height value incorrect\n  Template: 75\n  Response: " +
			std::to_string(t.height);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}

	std::cout << "T6 - 100x75 tile at (-10,-10): ";
	try {
		//Create a rectangular tile at (-10,-10) of size 100x75
		Tile t(-10, -10, 100, 75);

		//Ensure the top-left is at (-10,-10)
		if (t.topleft.first != -10 || t.topleft.second != -10) {
			std::string err = "Tile.topleft values incorrect\n";
			err += "  Template: (10, 10)\n";
			err += "  Response: (" + std::to_string(t.topleft.first);
			err += ", " + std::to_string(t.topleft.second) + ")";

			throw err;
		}

		//Ensure the top-right is at (90,-10)
		if (t.topright.first != 90 || t.topright.second != -10) {
			std::string err = "Tile.topright values incorrect\n";
			err += "  Template: (90, -10)\n";
			err += "  Response: (" + std::to_string(t.topright.first);
			err += ", " + std::to_string(t.topright.second) + ")";

			throw err;
		}

		//Ensure the bottom-left is at (-10,65)
		if (t.bottomleft.first != -10 || t.bottomleft.second != 65) {
			std::string err = "Tile.bottomleft values incorrect\n";
			err += "  Template: (-10, 65)\n";
			err += "  Response: (" + std::to_string(t.bottomleft.first);
			err += ", " + std::to_string(t.bottomleft.second) + ")";

			throw err;
		}

		//Ensure the bottom-right is at (90,65)
		if (t.bottomright.first != 90 || t.bottomright.second != 65) {
			std::string err = "Tile.bottomright values incorrect\n";
			err += "  Template: (90, 65)\n";
			err += "  Response: (" + std::to_string(t.bottomright.first);
			err += ", " + std::to_string(t.bottomright.second) + ")";

			throw err;
		}

		//Ensure the center is at (40,27)
		if (t.center.first != 40 || t.center.second != 27) {
			std::string err = "Tile.center values incorrect\n";
			err += "  Template: (40, 27)\n";
			err += "  Response: (" + std::to_string(t.center.first);
			err += ", " + std::to_string(t.center.second) + ")";

			throw err;
		}

		//Ensure the top is at -10
		if (t.top != -10)
			throw "Tile.top value incorrect\n  Template: -10\n  Response: " +
			std::to_string(t.left);

		//Ensure the bottom is at 65
		if (t.bottom != 65)
			throw "Tile.bottom value incorrect\n  Template: 65\n  Response: " +
			std::to_string(t.bottom);

		//Ensure the left is at -10
		if (t.left != -10)
			throw "Tile.left value incorrect\n  Template: -10\n  Response: " +
			std::to_string(t.left);

		//Ensure the right is at 90
		if (t.right != 90)
			throw "Tile.right value incorrect\n  Template: 90\n  Response: " +
			std::to_string(t.right);

		//Ensure the width is 90
		if (t.width != 100)
			throw "Tile.width value incorrect\n  Template: 100\n  Response: " +
			std::to_string(t.width);

		//Ensure the height is 75
		if (t.height != 75)
			throw "Tile.height value incorrect\n  Template: 75\n  Response: " +
			std::to_string(t.height);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}

	std::cout << "T7 - -100x100 tile at (0,0): ";
	try {
		//Create a tile with negative width to see if it fails
		Tile t(0, 0, -100, 100);

		std::cout << "Failed -> Tile with negative width created" << std::endl;
		passed = false;
	}
	catch (std::string err) { std::cout << "Passed" << std::endl; }
	catch (...) { std::cout << "Passed" << std::endl; }

	std::cout << "T8 - 100x-100 tile at (0,0): ";
	try {
		//Create a tile with negative height to see if it fails
		Tile t(0, 0, 100, -100);

		std::cout << "Failed -> Tile with negative height created" << std::endl;
		passed = false;
	}
	catch (std::string err) { std::cout << "Passed" << std::endl; }
	catch (...) { std::cout << "Passed" << std::endl; }

	std::cout << "T9 - 0x100 tile at (0,0): ";
	try {
		//Create a tile with zero width to see if it fails
		Tile t(0, 0, 0, 100);

		std::cout << "Failed -> Tile with zero width created" << std::endl;
		passed = false;
	}
	catch (std::string err) { std::cout << "Passed" << std::endl; }
	catch (...) { std::cout << "Passed" << std::endl; }

	std::cout << "T10 - 100x0 tile at (0,0): ";
	try {
		//Create a tile with zero height to see if it fails
		Tile t(0, 0, 100, 0);

		std::cout << "Failed -> Tile with zero height created" << std::endl;
		passed = false;
	}
	catch (std::string err) { std::cout << "Passed" << std::endl; }
	catch (...) { std::cout << "Passed" << std::endl; }

	passed ?
		std::cout << "All tests passed" << std::endl :
		std::cout << "At least one test failed" << std::endl;
	return passed;
}

void QuadNodeComp(QuadNode* node, particle* NE, particle* NW, particle* SW, particle* SE) {
	//Check that the node exists
	if (node == nullptr) throw "Node does not exist";

	//Gather the number of particles entered
	int pcount = 0;
	if (NE != nullptr) pcount++; if (NW != nullptr) pcount++;
	if (SW != nullptr) pcount++; if (SE != nullptr) pcount++;

	//Begin to compare the values to the inputs
	if (pcount == 1)
		if (node->getBody() == nullptr) throw "Body pointer null, should be populated";
		else
			if (node->getBody() != nullptr) throw "Body pointer not null, should be";

	//Check that the NE child is properly set
	if (NE == nullptr && node->getNE() != nullptr)
		throw "Northeast child incorrect\n  Template: " + to_string((uintptr_t)nullptr) +
		"\n  Response: " + to_string((uintptr_t)(node->getNE()));
	else if (NE != nullptr && node->getNE() == nullptr)
		throw "Northeast child null, should be populated";
	else if (node->getNE() != nullptr)
		if (node->getNE()->getBody() != NE)
			throw "Northeast child incorrect\n  Template: " + to_string((uintptr_t)(NE)) +
			"\n  Response: " + to_string((uintptr_t)(node->getNE()->getBody()));

	//Check that the NW child is properly set
	if (NW == nullptr && node->getNW() != nullptr)
		throw "Northwest child incorrect\n  Template: " + to_string((uintptr_t)nullptr) +
		"\n  Response: " + to_string((uintptr_t)(node->getNW()));
	else if (NW != nullptr && node->getNW() == nullptr)
		throw "Northwest child null, should be populated";
	else if (node->getNW() != nullptr)
		if (node->getNW()->getBody() != NW)
			throw "Northwest child incorrect\n  Template: " + to_string((uintptr_t)(NW)) +
			"\n  Response: " + to_string((uintptr_t)(node->getNW()->getBody()));

	//Check that the SW child is properly set
	if (SW == nullptr && node->getSW() != nullptr)
		throw "Southwest child incorrect\n  Template: " + to_string((uintptr_t)nullptr) +
		"\n  Response: " + to_string((uintptr_t)(node->getSW()));
	else if (SW != nullptr && node->getSW() == nullptr)
		throw "Southwest child null, should be populated";
	else if (node->getSW() != nullptr)
		if (node->getSW()->getBody() != SW)
			throw "Northeast child incorrect\n  Template: " + to_string((uintptr_t)(SW)) +
			"\n  Response: " + to_string((uintptr_t)(node->getSW()->getBody()));

	//Check that the SE child is properly set
	if (SE == nullptr && node->getSE() != nullptr)
		throw "Southeast child incorrect\n  Template: " + to_string((uintptr_t)nullptr) +
		"\n  Response: " + to_string((uintptr_t)(node->getSE()));
	else if (SE != nullptr && node->getSE() == nullptr)
		throw "Southeast child null, should be populated";
	else if (node->getSE() != nullptr)
		if (node->getSE()->getBody() != SE)
			throw "Southeast child incorrect\n  Template: " + to_string((uintptr_t)(SE)) +
			"\n  Response: " + to_string((uintptr_t)(node->getSE()->getBody()));

	//Ensure that the children have proper fields
	if (node->getNE() != nullptr) {
		QuadNode* NE = node->getNE();
		if (NE->getField().left != node->getField().center.first ||
			NE->getField().top != node->getField().top)
			throw "Northeast child field position incorrect\n  Template: (" +
			to_string(node->getField().center.first) + ", " + to_string(node->getField().top) +
			")\n  Response: (" + to_string(NE->getField().left) + ", " +
			to_string(NE->getField().top) + ")";
		if (NE->getField().width != node->getField().width / 2 ||
			NE->getField().height != node->getField().height / 2)
			throw "Northeast child field sizing incorrect\n  Template: (" +
			to_string(node->getField().width / 2) + ", " +
			to_string(node->getField().height / 2) + ")\n  Response: (" +
			to_string(NE->getField().width) + ", " + to_string(NE->getField().height) + ")";
	}
	if (node->getNW() != nullptr) {
		QuadNode* NW = node->getNW();
		if (NW->getField().left != node->getField().left ||
			NW->getField().top != node->getField().top)
			throw "Northwest child field position incorrect\n  Template: (" +
			to_string(node->getField().left) + ", " + to_string(node->getField().top) +
			")\n  Response: (" + to_string(NW->getField().left) + ", " +
			to_string(NW->getField().top) + ")";
		if (NW->getField().width != node->getField().width / 2 ||
			NW->getField().height != node->getField().height / 2)
			throw "Northwest child field sizing incorrect\n  Template: (" +
			to_string(node->getField().width / 2) + ", " +
			to_string(node->getField().height / 2) + ")\n  Response: (" +
			to_string(NW->getField().width) + ", " + to_string(NW->getField().height) + ")";
	}
	if (node->getSW() != nullptr) {
		QuadNode* SW = node->getSW();
		if (SW->getField().left != node->getField().left ||
			SW->getField().top != node->getField().center.second)
			throw "Southwest child field position incorrect\n  Template: (" +
			to_string(node->getField().left) + ", " +
			to_string(node->getField().center.second) +
			")\n  Response: (" + to_string(SW->getField().left) + ", " +
			to_string(SW->getField().top) + ")";
		if (SW->getField().width != node->getField().width / 2 ||
			SW->getField().height != node->getField().height / 2)
			throw "Southwest child field sizing incorrect\n  Template: (" +
			to_string(node->getField().width / 2) + ", " +
			to_string(node->getField().height / 2) + ")\n  Response: (" +
			to_string(SW->getField().width) + ", " + to_string(SW->getField().height) + ")";
	}
	if (node->getSE() != nullptr) {
		QuadNode* SE = node->getSE();
		if (SE->getField().left != node->getField().center.first ||
			SE->getField().top != node->getField().center.second)
			throw "Southeast child field position incorrect\n  Template: (" +
			to_string(node->getField().center.first) + ", " +
			to_string(node->getField().center.second) +
			")\n  Response: (" + to_string(SE->getField().left) + ", " +
			to_string(SE->getField().top) + ")";
		if (SE->getField().width != node->getField().width / 2 ||
			SE->getField().height != node->getField().height / 2)
			throw "Southeast child field sizing incorrect\n  Template: (" +
			to_string(node->getField().width / 2) + ", " +
			to_string(node->getField().height / 2) + ")\n  Response: (" +
			to_string(SE->getField().width) + ", " + to_string(SE->getField().height) + ")";
	}

	//Check that the total mass was correct
	int totmass = 0;
	if (NE != nullptr) totmass += NE->mass; if (NW != nullptr) totmass += NW->mass;
	if (SW != nullptr) totmass += SW->mass; if (SE != nullptr) totmass += SE->mass;
	if (node->getMass() != totmass)
		throw "Mass value incorrect\n  Template: " + to_string(totmass) +
		"\n  Response: " + to_string(node->getMass());

	//Check that the center of mass was correct
	double NEperc = (NE == nullptr ? 0 : (double)NE->mass / totmass);
	double NWperc = (NW == nullptr ? 0 : (double)NW->mass / totmass);
	double SWperc = (SW == nullptr ? 0 : (double)SW->mass / totmass);
	double SEperc = (SE == nullptr ? 0 : (double)SE->mass / totmass);

	int centx = 0, centy = 0;
	if (NE != nullptr) { centx += NE->xpos * NEperc; centy += NE->ypos * NEperc; }
	if (NW != nullptr) { centx += NW->xpos * NWperc; centy += NW->ypos * NWperc; }
	if (SW != nullptr) { centx += SW->xpos * SWperc; centy += SW->ypos * SWperc; }
	if (SE != nullptr) { centx += SE->xpos * SEperc; centy += SE->ypos * SEperc; }

	if (node->getMassCenter().first != centx || node->getMassCenter().second != centy)
		throw "Center of mass incorrect\n  Template: (" + to_string(centx) + ", " +
		to_string(centy) + ")\n  Response: (" + to_string(node->getMassCenter().first) +
		", " + to_string(node->getMassCenter().second) + ")";

	return;
}
bool testQuadNode() {
	std::cout << "Testing Quad Node functionality" << std::endl;
	bool passed = true;


	std::cout << "T1 - Constructor test, 100x100 field at (-50,-50): ";
	try {
		//Provide dimensions information for the field of a new QuadNode
		QuadNode node = QuadNode(-50, -50, 100, 100);
		//Access the field created for evaluation
		Tile t = node.getField();

		//Ensure the edges were created properly
		if (t.top != -50 || t.bottom != 50 || t.left != -50 || t.right != 50) {
			throw "QuadNode->field simple positions incorrect\n" +
				(std::string)"  Template:\t\tResponse:\n" +
				(std::string)"  - top == -50   \t- top == " + std::to_string(t.top) +
				"\n  - bottom == 50\t- bottom == " + std::to_string(t.bottom) +
				"\n  - left == -50  \t- left == " + std::to_string(t.left) +
				"\n  - right == 50  \t- right == " + std::to_string(t.right);
		}

		//Ensure the sizes were created properly
		if (t.width != 100 || t.height != 100) {
			throw "QuadNode->field dimensions incorrect\n" +
				(std::string)"  Template: w == 100, h == 100\n" +
				(std::string)"  Response: w == " + std::to_string(t.width) +
				", h == " + std::to_string(t.height);
		}

		//Ensure the center was set properly
		if (t.center.first != 0 || t.center.second != 0) {
			throw "QuadNode->Field center incorrect\n" +
				(std::string)"  Template: Center at (0,0)\n  Response: Center at (" +
				std::to_string(t.center.first) + ", " + std::to_string(t.center.second) +
				")";
		}

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> Unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T2 - Constructor test, -10x40 field at (15, 0): ";
	try {
		//Provide dimension informationf or the field of a new QuadNode
		QuadNode node = QuadNode(15, 0, -10, 40);
		
		//A successful field creation means it failed to filter negative values
		std::cout << "Failed -> Field with negative width created" << std::endl;
		passed = false;
	}
	catch (...) { std::cout << "Passed" << std::endl; }


	std::cout << "T3 - Insert Test, empty node: ";
	try {
		//Create a particle to insert into the node
		particle p(20, 20, 10, 1);
		//Create a node with a 100x100 field at (0,0)
		QuadNode node = QuadNode(0, 0, 100, 100);

		//Attempt to insert the particle into the node
		node.insert(&p);

		//Check that the body was inserted properly
		if (node.getBody() != &p) {
			throw "Body pointer incorrect\n  Template: " +
				std::to_string((unsigned long long)(&p)) +
				"\n  Response: " + std::to_string((unsigned long long)(node.getBody()));
		}

		//Check that the child nodes are empty
		if (node.getNE() != nullptr) throw "Northeast Child not null";
		if (node.getNW() != nullptr) throw "Northwest Child not null";
		if (node.getSW() != nullptr) throw "Southwest Child not null";
		if (node.getSE() != nullptr) throw "Southeast Child not null";

		//Check that the node is marked as a leaf
		if (node.isLeaf() == false) throw "Node not properly marked as leaf";

		//Check that the node's total mass is correct
		if (node.getMass() != p.mass) throw "Aggregate mass value incorrect";

		//Check that the node's center of mass is correct
		if (node.getMassCenter().first  != p.xpos ||
			node.getMassCenter().second != p.ypos) {
			throw "Node center of mass incorrect\n  Template: (" +
				std::to_string(p.xpos) + ", " + std::to_string(p.ypos) +
				")\n Response: (" +
				std::to_string(node.getMassCenter().first) + ", " +
				std::to_string(node.getMassCenter().second) + ")";
		}

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> Unknown error" << std::endl;
		passed = false;
	}
	

	std::cout << "T4 - Insert Test NE-NW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, &p1, &p2, nullptr, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T5 - Insert Test NE-SW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, &p1, nullptr, &p2, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T6 - Insert Test NE-SE: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, &p1, nullptr, nullptr, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T7 - Insert Test NW-NE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, &p2, &p1, nullptr, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T8 - Insert Test NW-SW: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, nullptr, &p1, &p2, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T9 - Insert Test NW-SE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, nullptr, &p1, nullptr, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T10 - Insert Test SW-NE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, &p2, nullptr, &p1, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T11 - Insert Test SW-NW: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, nullptr, &p2, &p1, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T12 - Insert Test SW-SE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, nullptr, nullptr, &p1, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T13 - Insert Test NE-NW-SW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p1, &p2, &p3, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T14 - Insert Test NE-NW-SE: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p1, &p2, nullptr, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T15 - Insert Test NE-SW-NW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p1, &p3, &p2, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T16 - Insert Test NE-SW-SE: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p1, nullptr, &p2, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T17 - Insert Test NE-SE-NW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p1, &p3, nullptr, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T18 - Insert Test NE-SE-SW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p1, nullptr, &p3, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T19 - Insert Test NW-NE-SW: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p2, &p1, &p3, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T20 - Insert Test NW-NE-SE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p2, &p1, nullptr, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T21 - Insert Test NW-SW-NE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p3, &p1, &p2, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T22 - Insert Test NW-SW-SE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, nullptr, &p1, &p2, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T23 - Insert Test NW-SE-NE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p3, &p1, nullptr, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T24 - Insert Test NW-SE-SW: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, nullptr, &p1, &p3, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T25 - Insert Test SW-NE-NW: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p2, &p3, &p1, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T26 - Insert Test SW-NE-SE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p2, nullptr, &p1, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T27 - Insert Test SW-NW-NE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p3, &p2, &p1, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T28 - Insert Test SW-NW-SE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, nullptr, &p2, &p1, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T29 - Insert Test SW-SE-NE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p3, nullptr, &p1, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T30 - Insert Test SW-SE-NW: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, nullptr, &p3, &p1, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T31 - Insert Test NE-NW-SW-SE: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(25, 75, 10, 1);
		particle p4(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p1, &p2, &p3, &p4);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T32 - Insert Test NE-NW-SE-SW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(75, 75, 10, 1);
		particle p4(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p1, &p2, &p4, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T33 - Insert Test NE-SW-NW-SE: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(25, 25, 10, 1);
		particle p4(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p1, &p3, &p2, &p4);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T34 - Insert Test NE-SW-SE-NW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(75, 75, 10, 1);
		particle p4(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p1, &p4, &p2, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T35 - Insert Test NE-SE-NW-SW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 25, 10, 1);
		particle p4(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p1, &p3, &p4, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T36 - Insert Test NE-SE-SW-NW: ";
	try {
		particle p1(75, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 75, 10, 1);
		particle p4(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p1, &p4, &p3, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T37 - Insert Test NW-NE-SW-SE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(25, 75, 10, 1);
		particle p4(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p2, &p1, &p3, &p4);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T38 - Insert Test NW-NE-SE-SW: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(75, 75, 10, 1);
		particle p4(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p2, &p1, &p4, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T39 - Insert Test NW-SW-NE-SE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(75, 25, 10, 1);
		particle p4(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p3, &p1, &p2, &p4);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T40 - Insert Test NW-SW-SE-NE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(25, 75, 10, 1);
		particle p3(75, 75, 10, 1);
		particle p4(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p4, &p1, &p2, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T41 - Insert Test NW-SE-NE-SW: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(75, 25, 10, 1);
		particle p4(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p3, &p1, &p4, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T42 - Insert Test NW-SE-SW-NE: ";
	try {
		particle p1(25, 25, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 75, 10, 1);
		particle p4(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p4, &p1, &p3, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T43 - Insert Test SW-NE-NW-SE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(25, 25, 10, 1);
		particle p4(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p2, &p3, &p1, &p4);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T44 - Insert Test SW-NE-SE-NW: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 25, 10, 1);
		particle p3(75, 75, 10, 1);
		particle p4(25, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p2, &p4, &p1, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T45 - Insert Test SW-NW-NE-SE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(75, 25, 10, 1);
		particle p4(75, 75, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p3, &p2, &p1, &p4);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T46 - Insert Test SW-NW-SE-NE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(25, 25, 10, 1);
		particle p3(75, 75, 10, 1);
		particle p4(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p4, &p2, &p1, &p3);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T47 - Insert Test SW-SE-NE-NW: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(75, 25, 10, 1);
		particle p4(25, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p3, &p4, &p1, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T48 - Insert Test SW-SE-NW-NE: ";
	try {
		particle p1(25, 75, 10, 1);
		particle p2(75, 75, 10, 1);
		particle p3(25, 25, 10, 1);
		particle p4(75, 25, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p4, &p3, &p1, &p2);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T49 - Mass Center Test, 2 Particles: ";
	try {
		particle p1(89, 41, 10, 0);
		particle p2(29, 72, 10, 2);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, &p1, nullptr, &p2, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T50 - Mass Center Test, 2 Particles: ";
	try {
		particle p1(12, 16, 10, 1);
		particle p2(26, 51, 10, 4);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);

		QuadNodeComp(&node, nullptr, &p1, &p2, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T51 - Mass Center Test, 3 Particles: ";
	try {
		particle p1(66, 7, 10, 0);
		particle p2(19, 44, 10, 1);
		particle p3(47, 52, 10, 4);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p1, &p2, &p3, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T52 - Mass Center Test, 3 Particles: ";
	try {
		particle p1(1, 99, 10, 3);
		particle p2(26, 37, 10, 3);
		particle p3(94, 17, 10, 1);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		QuadNodeComp(&node, &p3, &p2, &p1, nullptr);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T53 - Mass Center Test, 4 Particles: ";
	try {
		particle p1(51, 71, 10, 0);
		particle p2(6, 11, 10, 2);
		particle p3(28, 76, 10, 2);
		particle p4(83, 42, 10, 4);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p4, &p2, &p3, &p1);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T54 - Mass Center Test, 4 Particles: ";
	try {
		particle p1(77, 51, 10, 0);
		particle p2(40, 7, 10, 0);
		particle p3(8, 92, 10, 0);
		particle p4(80, 9, 10, 4);

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		QuadNodeComp(&node, &p4, &p2, &p3, &p1);

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T55 - Double Insert Test, NE: ";
	try {
		//Create two particles for the northeast quadrant
		particle p1(60, 10, 10, 1); //NE->NW
		particle p2(90, 15, 10, 1); //NE->NE

		QuadNode node(0, 0, 100, 100);

		//Insert both into the same 
		node.insert(&p1);
		node.insert(&p2);

		//Check that the node's body is empty
		if (node.getBody() != nullptr)
			throw "Body pointer incorrect\n  Template: " + to_string((uintptr_t)(nullptr)) +
			"\n  Response: " + to_string((uintptr_t)(node.getBody()));

		//Check that the Northeast Child is correct
		if (node.getNE() == nullptr) throw "Northeast child null, should be populated";
		//Check that the Northwest Child is correct
		if (node.getNW() != nullptr) throw "Northwest child not null";
		//Check that the Southwest Child is correct
		if (node.getSW() != nullptr) throw "Southwest child not null";
		//Check that the Southeast Child is correct
		if (node.getSE() != nullptr) throw "Southeast child not null";

		//Store the northeast child for further testing
		QuadNode* child = node.getNE();

		//Check that the child has no body
		if (child->getBody() != nullptr) throw "Body pointer incorrect\n  Template: " +
			to_string((uintptr_t)nullptr) + "\n  Response: " +
			to_string((uintptr_t)(child->getBody()));

		//Check that the Northeast node's children are correct
		if (child->getNE() == nullptr) throw "NE->NE child null, should be populated";
		if (child->getNW() == nullptr) throw "NE->NW child null, should be populated";
		if (child->getSW() != nullptr) throw "NE->SW child not null";
		if (child->getSE() != nullptr) throw "NE->SE child not null";

		try { QuadNodeComp(child, &p2, &p1, nullptr, nullptr); }
		catch (std::string err) { throw "From Northeast Child: " + err; }
		catch (const char* err) { throw "From Northeast Child: " + (std::string)err; }
		catch (...) { throw "From Northeast Child: unknown error"; }

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T56 - Double Insert Test, NW: ";
	try {
		//Create two particles for the northeast quadrant
		particle p1(15, 32, 10, 1); //NW->SW
		particle p2(27, 40, 10, 1); //NW->SE

		QuadNode node(0, 0, 100, 100);

		//Insert both into the same 
		node.insert(&p1);
		node.insert(&p2);

		//Check that the node's body is empty
		if (node.getBody() != nullptr)
			throw "Body pointer incorrect\n  Template: " + to_string((uintptr_t)(nullptr)) +
			"\n  Response: " + to_string((uintptr_t)(node.getBody()));

		//Check that the Northeast Child is correct
		if (node.getNE() != nullptr) throw "Northeast child not null";
		//Check that the Northwest Child is correct
		if (node.getNW() == nullptr) throw "Northwest child null, should be populated";
		//Check that the Southwest Child is correct
		if (node.getSW() != nullptr) throw "Southwest child not null";
		//Check that the Southeast Child is correct
		if (node.getSE() != nullptr) throw "Southeast child not null";

		//Store the northeast child for further testing
		QuadNode* child = node.getNW();

		//Check that the child has no body
		if (child->getBody() != nullptr) throw "Body pointer incorrect\n  Template: " +
			to_string((uintptr_t)nullptr) + "\n  Response: " +
			to_string((uintptr_t)(child->getBody()));

		//Check that the Northeast node's children are correct
		if (child->getNE() != nullptr) throw "NW->NE child not null";
		if (child->getNW() != nullptr) throw "NW->NW child not null";
		if (child->getSW() == nullptr) throw "NW->SW child null, should be populated";
		if (child->getSE() == nullptr) throw "NW->SE child null, should be populated";

		try { QuadNodeComp(child, nullptr, nullptr, &p1, &p2); }
		catch (std::string err) { throw "From Northwest Child: " + err; }
		catch (const char* err) { throw "From Northwest Child: " + (std::string)err; }
		catch (...) { throw "From Northwest Child: unknown error"; }

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T57 - Double Insert Test, SW: ";
	try {
		//Create two particles for the northeast quadrant
		particle p1(10, 60, 10, 1); //SW->NW
		particle p2(48, 83, 10, 1); //SW->SE

		QuadNode node(0, 0, 100, 100);

		//Insert both into the same 
		node.insert(&p1);
		node.insert(&p2);

		//Check that the node's body is empty
		if (node.getBody() != nullptr)
			throw "Body pointer incorrect\n  Template: " + to_string((uintptr_t)(nullptr)) +
			"\n  Response: " + to_string((uintptr_t)(node.getBody()));

		//Check that the Northeast Child is correct
		if (node.getNE() != nullptr) throw "Northeast child not null";
		//Check that the Northwest Child is correct
		if (node.getNW() != nullptr) throw "Northwest child not null";
		//Check that the Southwest Child is correct
		if (node.getSW() == nullptr) throw "Southwest child null, should be populated";
		//Check that the Southeast Child is correct
		if (node.getSE() != nullptr) throw "Southeast child not null";

		//Store the northeast child for further testing
		QuadNode* child = node.getSW();

		//Check that the child has no body
		if (child->getBody() != nullptr) throw "Body pointer incorrect\n  Template: " +
			to_string((uintptr_t)nullptr) + "\n  Response: " +
			to_string((uintptr_t)(child->getBody()));

		//Check that the Northeast node's children are correct
		if (child->getNE() != nullptr) throw "SW->NE child not null";
		if (child->getNW() == nullptr) throw "SW->NW child null, should be populated";
		if (child->getSW() != nullptr) throw "SW->SW child not null";
		if (child->getSE() == nullptr) throw "SW->SE child null, should be populated";

		try { QuadNodeComp(child, nullptr, &p1, nullptr, &p2); }
		catch (std::string err) { throw "From Southwest Child: " + err; }
		catch (const char* err) { throw "From Southwest Child: " + (std::string)err; }
		catch (...) { throw "From Southwest Child: unknown error"; }

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}

	std::cout << "T58 - Double Insert Test, SE: ";
	try {
		//Create two particles for the northeast quadrant
		particle p1(51, 51, 10, 1); //SE->NW
		particle p2(85, 68, 10, 1); //SE->NE

		QuadNode node(0, 0, 100, 100);

		//Insert both into the same 
		node.insert(&p1);
		node.insert(&p2);

		//Check that the node's body is empty
		if (node.getBody() != nullptr)
			throw "Body pointer incorrect\n  Template: " + to_string((uintptr_t)(nullptr)) +
			"\n  Response: " + to_string((uintptr_t)(node.getBody()));

		//Check that the Northeast Child is correct
		if (node.getNE() != nullptr) throw "Northeast child not null";
		//Check that the Northwest Child is correct
		if (node.getNW() != nullptr) throw "Northwest child not null";
		//Check that the Southwest Child is correct
		if (node.getSW() != nullptr) throw "Southwest child not null";
		//Check that the Southeast Child is correct
		if (node.getSE() == nullptr) throw "Southeast child null, should be populated";

		//Store the northeast child for further testing
		QuadNode* child = node.getSE();

		//Check that the child has no body
		if (child->getBody() != nullptr) throw "Body pointer incorrect\n  Template: " +
			to_string((uintptr_t)nullptr) + "\n  Response: " +
			to_string((uintptr_t)(child->getBody()));

		//Check that the Northeast node's children are correct
		if (child->getNE() == nullptr) throw "SW->NE child null, should be populated";
		if (child->getNW() == nullptr) throw "SW->NW child null, should be populated";
		if (child->getSW() != nullptr) throw "SW->SW child not null";
		if (child->getSE() != nullptr) throw "SW->SE child not null";

		try { QuadNodeComp(child, &p2, &p1, nullptr, nullptr); }
		catch (std::string err) { throw "From Southeast Child: " + err; }
		catch (const char* err) { throw "From Southeast Child: " + (std::string)err; }
		catch (...) { throw "From Southeast Child: unknown error"; }

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T59 - Complex Mass Test, 2 Children/3 Particles: ";
	try {
		particle p1(15, 20, 10, 1); //NW->NW
		particle p2(38, 79, 10, 1); //SW->SE
		particle p3(47, 18, 10, 1); //NW->NE

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);

		//Ensure the children are properly populated
		if (node.getNW() == nullptr) throw "Northwest child null, should be populated";
		if (node.getSW() == nullptr) throw "Southwest child null, should be populated";

		//Ensure the Northwest child's mass is correct
		if (node.getNW()->getMass() != p1.mass + p3.mass)
			throw "Northwest child total mass incorrect\n  Template: " +
			to_string(p1.mass + p3.mass) + "\n  Response: " +
			to_string(node.getNW()->getMass());

		if (node.getNW()->getMassCenter().first != (p1.xpos + p3.xpos) / 2 ||
			node.getNW()->getMassCenter().second != (p1.ypos + p3.ypos) / 2)
			throw "Northwest child center of mass incorrect\n  Template: (" +
			to_string((p1.xpos + p3.xpos) / 2) + ", " + to_string((p1.ypos + p3.ypos) / 2) +
			")\n  Response: (" + to_string(node.getNW()->getMassCenter().first) + ", " +
			to_string(node.getNW()->getMassCenter().second) + ")";

		//Ensure that the Southwest child's mass is correct
		if (node.getSW()->getMass() != p2.mass)
			throw "Southwest child total mass incorrect\n  Template: " +
			to_string(p2.mass) + "\n  Response: " +
			to_string(node.getSW()->getMass());

		if (node.getSW()->getMassCenter().first != p2.xpos ||
			node.getSW()->getMassCenter().second != p2.ypos)
			throw "Southwest child center of mass incorrect\n  Template: (" +
			to_string(p2.xpos) + ", " + to_string(p2.ypos) + ")\n  Response: (" +
			to_string(node.getSW()->getMassCenter().first) + ", " +
			to_string(node.getSW()->getMassCenter().second) + ")";

		//Ensure that the node's mass is correct
		if (node.getMass() != p1.mass + p2.mass + p3.mass)
			throw "Total mass incorrect\n  Template: " +
			to_string(p1.mass + p2.mass + p3.mass) + "\n  Response: " +
			to_string(node.getMass());

		if (node.getMassCenter().first != (p1.xpos + p2.xpos + p3.xpos) / 3 ||
			node.getMassCenter().second != (p1.ypos + p2.ypos + p3.ypos) / 3)
			throw "Center of mass incorrect\n  Template: (" +
			to_string((p1.xpos + p2.xpos + p3.xpos) / 3) + ", " +
			to_string((p1.ypos + p2.ypos + p3.ypos) / 3) + "\n Response: (" +
			to_string(node.getMassCenter().first) + ", " +
			to_string(node.getMassCenter().second) + ")";

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	std::cout << "T60 - Complex Mass Test, 2 Children/4 Particles";
	try {
		particle p1(15, 20, 10, 1); //NW->NW
		particle p2(38, 79, 10, 1); //SW->SE
		particle p3(47, 18, 10, 1); //NW->NE
		particle p4(11, 93, 10, 1); //SW->SW

		QuadNode node(0, 0, 100, 100);

		node.insert(&p1);
		node.insert(&p2);
		node.insert(&p3);
		node.insert(&p4);

		//Ensure the children are properly populated
		if (node.getNW() == nullptr) throw "Northwest child null, should be populated";
		if (node.getSW() == nullptr) throw "Southwest child null, should be populated";

		//Ensure the Northwest child's mass is correct
		if (node.getNW()->getMass() != p1.mass + p3.mass)
			throw "Northwest child total mass incorrect\n  Template: " +
			to_string(p1.mass + p3.mass) + "\n  Response: " +
			to_string(node.getNW()->getMass());

		if (node.getNW()->getMassCenter().first != (p1.xpos + p3.xpos) / 2 ||
			node.getNW()->getMassCenter().second != (p1.ypos + p3.ypos) / 2)
			throw "Northwest child center of mass incorrect\n  Template: (" +
			to_string((p1.xpos + p3.xpos) / 2) + ", " + to_string((p1.ypos + p3.ypos) / 2) +
			")\n  Response: (" + to_string(node.getNW()->getMassCenter().first) + ", " +
			to_string(node.getNW()->getMassCenter().second) + ")";

		//Ensure that the Southwest child's mass is correct
		if (node.getSW()->getMass() != p2.mass + p4.mass)
			throw "Southwest child total mass incorrect\n  Template: " +
			to_string(p2.mass + p4.mass) + "\n  Response: " +
			to_string(node.getSW()->getMass());

		if (node.getSW()->getMassCenter().first != (p2.xpos + p4.xpos) / 2 ||
			node.getSW()->getMassCenter().second != (p2.ypos + p4.ypos) / 2)
			throw "Southwest child center of mass incorrect\n  Template: (" +
			to_string((p2.xpos + p4.xpos) / 2) + ", " +
			to_string((p2.ypos + p4.ypos) / 2) + ")\n  Response: (" +
			to_string(node.getSW()->getMassCenter().first) + ", " +
			to_string(node.getSW()->getMassCenter().second) + ")";

		//Ensure that the node's mass is correct
		if (node.getMass() != p1.mass + p2.mass + p3.mass + p4.mass)
			throw "Total mass incorrect\n  Template: " +
			to_string(p1.mass + p2.mass + p3.mass + p4.mass) + "\n  Response: " +
			to_string(node.getMass());

		if (node.getMassCenter().first != (p1.xpos + p2.xpos + p3.xpos + p4.xpos) / 4 ||
			node.getMassCenter().second != (p1.ypos + p2.ypos + p3.ypos + p4.ypos) / 4)
			throw "Center of mass incorrect\n  Template: (" +
			to_string((p1.xpos + p2.xpos + p3.xpos + p4.xpos) / 4) + ", " +
			to_string((p1.ypos + p2.ypos + p3.ypos + p4.xpos) / 4) + "\n Response: (" +
			to_string(node.getMassCenter().first) + ", " +
			to_string(node.getMassCenter().second) + ")";

		std::cout << "Passed" << std::endl;
	}
	catch (std::string err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (const char* err) {
		std::cout << "Failed -> " << err << std::endl;
		passed = false;
	}
	catch (...) {
		std::cout << "Failed -> unknown error" << std::endl;
		passed = false;
	}


	passed ?
		std::cout << "All tests passed" << std::endl :
		std::cout << "At least one test failed" << std::endl;
	return passed;
}


#endif