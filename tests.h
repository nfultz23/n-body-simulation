#ifndef TESTS_H
#define TESTS_H

#include <iostream>
#include <cstdlib>
#include <string>
#include <exception>

#include "./Quadtree.h"


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

	passed ? std::cout << "All tests passed" << std::endl : std::cout << "At least one test failed" << std::endl;
	return passed;
}

#endif