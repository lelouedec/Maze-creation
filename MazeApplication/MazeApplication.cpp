// MazeApplication.cpp : définit le point d'entrée pour l'application console.
//

#include <stdio.h>
#include <stdlib.h>
#include "stdafx.h"
#include "Maze.h"




int main(int argc, char **argv) {
	
	//specify lentgh and with of the maze
	int width = 25;
	int heigth = 20;

	//create the maze with width and height specified	
	Maze maze;
	maze.Create_Maze(width,heigth);
	maze.Draw();

	return 0;
}

