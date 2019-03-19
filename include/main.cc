#include <iostream>
#include "maze_generator.h"
#include <map>

using namespace std;

int main(){
	MazeGen maze = MazeGen();
	// maze.printMaze();
	int lifeVal = 20;
	int l = maze.mazesize();
	int endP = l*l - 1;
	int round = 0;
	bool visitC = false;
	string control;
	
	//cout<<"robotP: "<<maze.robotP()<<endl;
	while (lifeVal > 0 && maze.robotP() != endP){
		cout<<"\n"<<endl;
		round += 1;
		cout<<"ROUND "<<round<<endl;
		maze.printMaze();
		cout<<"Current life value:"<<lifeVal<<endl;
		cout<<"Press 'a,s,d,w' to control your robot:"<<endl;
		cout<<"Press 'r' to reset your robot:"<<endl;
		getline (cin, control);
		maze.updateRobotP(control);
		
		if (maze.opVal()){
			if (maze.robotP() == maze.getCharP()){
				if (visitC == false){
					lifeVal += 10;
					visitC = true;
				}
			} else {
				lifeVal -= maze.getValue(maze.robotP());
			}
				
			cout<<"Current life value:"<<lifeVal<<endl;
		} else{
			cout<<"Invalid control, please enter again."<<endl;
			round -= 1;
		}
		

	}
	if (lifeVal <= 0){
		cout<<"Game Over!"<<endl;
	} else if (lifeVal > 0 && maze.robotP() == endP){
		cout<<"Congratulations!"<<endl;
		maze.printMaze();
	}
}