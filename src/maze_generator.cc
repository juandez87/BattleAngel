#include <iostream>
#include <map>
#include <cstdlib>
#include <stdlib.h>
#include <time.h> 
#include "maze_generator.h"

using namespace std;

MazeGen::MazeGen(){
	cout<<"Maze will be generated based on the default size.\n";
	_maze_size = 12;
	srand(time(0)); 
	_chargeP = rand() % 100;
	while (_chargeP == 0 || _chargeP == 99){
		_chargeP = rand() % 100;
	}
	_robot_p = 0;
	mazeIni(_maze_size, _chargeP);

}

MazeGen::MazeGen(int size, int chargeP){
	if(size < 1){
		cout<<"Maze will be generated based on the default size.\n";
		size  = 10;
		_maze_size = 10;
	} else{
		_maze_size = size;
	}
	srand(time(0)); 
	if (chargeP == 0 || chargeP >= (size * size)){
		cout<<"Can not set the position for charger. Charger will be put randomly\n";
		_chargeP = rand() % (size * size);
		while (_chargeP == 0 || _chargeP == (size * size - 1)){
			_chargeP = rand() % (size * size);
		}
	} else{
		_chargeP = chargeP;
	}
	_robot_p = 0;
	mazeIni(_maze_size, chargeP);

}

void MazeGen::updateRobotP(std::string op){
	// back one step
	_opValid = false;
	if(op == "a"){
		if (_robot_p % _maze_size != 0){
			_robot_p -= 1;
			_opValid = true;
		}
	}
	// forward one step
	if(op == "d"){
		if ((_robot_p + 1) % _maze_size != 0 || (_robot_p+1) == (_maze_size) * (_maze_size) -1){
			_robot_p += 1;
			_opValid = true;
		}	
	}
	// back one line
	if(op == "w"){
		if (_robot_p - _maze_size >= 0){
			_robot_p -= _maze_size;
			_opValid = true;
		}	
	}
	// forward one line
	if(op == "s"){
		if (_robot_p + _maze_size < (_maze_size * _maze_size)){
			_robot_p += _maze_size;
			_opValid = true;
		}	
	}

	if(op == "r"){
		_robot_p = 0;
		_visitC = false;	
		_opValid = true;
	}
	checkC(_robot_p);
}

int MazeGen::mazesize(){
	return _maze_size;
}

void MazeGen::mazeIni(int size, int chargeP){
	int idx_max = (size) * (size);
	srand(time(0)); 
	for (int i = 0; i < (idx_max); i++){
		if(i != chargeP){
			// cout<<"GEN"<<rand() % 3<<" ";
			_maze[i] = rand() % 3;
			// cout<<"MAZE"<<_maze[i]<<" "<<"\n";
		} else{
			_maze[i] = 10;
		}
	}
	_maze[0] = 0;
	_visitC = false;
}

int MazeGen::robotP(){
	return _robot_p;
}

int MazeGen::getCharP(){
	return _chargeP;
}

bool MazeGen::opVal(){
	return _opValid;
}
void MazeGen::printMaze(){
	int idx = _maze_size * _maze_size;

	for (int i = 0; i < idx; i++ ){
		if (i == _robot_p){
			cout<<"*S*";
		} else if(i == _chargeP){
			cout<<"$$$";
		} else if(i == idx - 1){
			cout<<"*E*";
		}else{
			cout<<"-"<<_maze[i]<<"-";
		}
		if (i % _maze_size == _maze_size - 1){
			cout<<"\n";
		}
	}
}

void MazeGen::checkC(int p){
	if(p == _chargeP){
		_maze[_chargeP] = 0;
		_visitC = true;
	}
}

int MazeGen::getValue(int p){
	return _maze[p];
}









