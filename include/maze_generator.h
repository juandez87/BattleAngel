#ifndef _MAZE_GENERATOR_H
#define _MAZE_GENERATOR_H

#include <iostream>
#include <map>
#include <string>

using namespace std;


class MazeGen{
public:
	// default constructor
	MazeGen();
	MazeGen(int size, int chargePosition);

	void mazeIni(int size, int chargePosition);

	void updateRobotP(std::string op);

	// return robot current position
	int robotP();
	int mazesize();
	void printMaze();
	void checkC(int p);
	int getValue(int p);
	int getCharP();
	bool opVal();

private:
	int _robot_p;
	int _chargeP;
	map<int, int> _maze;
	int _maze_size;// m * m, m = _maze_size;
	bool _visitC;
	bool _opValid;

};

#endif