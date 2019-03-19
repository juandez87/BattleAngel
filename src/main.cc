#include <iostream>
#include "maze_generator.h"
#include <map>

using namespace std;

int main(){
	int lifeVal = 0;
	string difficulity;
	while (lifeVal == 0){
		cout << "\033[1;31mPlease set the difficulity for this game.\033[0m\n";
		cout << "\033[1;31mEasy(press 1), Medium(press 2), Hard(press 3)\033[0m\n";
		getline (cin, difficulity);

		if (difficulity == "1"){
			lifeVal = 30;
		} else if(difficulity == "2"){
			lifeVal = 20;
		} else if(difficulity == "3"){
			lifeVal = 10;
		} else{
			cout << "\033[1;31mInvalid input, please enter again.\033[0m\n";
		}

	}
	cout<<"\n"<<endl;
	cout<<"\033[1;31mWelcome to the game of Battle Angel!\033[0m\n";
	MazeGen maze = MazeGen();
	int l = maze.mazesize();
	int endP = l*l - 1;
	int round = 0;
	bool visitC = false;
	string control;
	// cout << "\033[1;31mbold red text\033[0m\n";
	//cout<<"robotP: "<<maze.robotP()<<endl;
	while (lifeVal > 0 && maze.robotP() != endP){
		// 
		round += 1;
		cout<<"ROUND "<<round<<endl;
		maze.printMaze();
		cout<<"Current life value:"<<lifeVal<<endl;
		cout<<"Press 'a,s,d,w' to control your robot:"<<endl;
		cout<<"(Press 'r' to reset your robot)"<<endl;
		getline (cin, control);
		maze.updateRobotP(control);
		
		if (control == "r"){
			lifeVal = 20;
			visitC = false;
		}

		if (maze.opVal()){
			if (maze.robotP() == maze.getCharP()){
				if (visitC == false){
					lifeVal += 10;
					visitC = true;
				}
			} else {
				lifeVal -= maze.getValue(maze.robotP());
			}
				
			// cout<<"Current life value:"<<lifeVal<<endl;
		} else{
			cout << "\033[1;31mInvalid control, please enter again.\033[0m\n";
			round -= 1;
		}
		

	}
	if (lifeVal <= 0){
		cout<<"\033[1;31mGame Over!\033[0m\n"<<endl;
	} else if (lifeVal > 0 && maze.robotP() == endP){
		cout<<"\033[1;31mCongratulations!\033[0m\n"<<endl;
		cout<<"Your battle angel wins the game with "<<lifeVal<<" life value left!"<<endl;
		// maze.printMaze();
	}
}