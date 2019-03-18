#include <iostream>
#include <vector>
#include <string>
#include "gtest/gtest.h"
#include "maze_generator.h"


namespace {

    TEST(Basic,Construction) { 
    	MazeGen maze = MazeGen();
		maze.printMaze();
        ASSERT_EQ(0, maze.robotP());
    }

    // More tests go here. You should aim to test every
    // method of every object, either directly or indirectly,
    // although testing user interfaces is notoriously 
    // difficult.

}