#include "Tree.h"
using namespace std;

class Maze {

public: 


	Tree tree;
	int minimum= 1;//minimum size of a space in the maze
	int seed = 14632532;


	void Create_Maze(int width, int height);
	void dividenode(Node * node);
	void printTheMaze();
	void solver(Node * exit, Node * dropedin);
	void Draw();
	void findParents(Node * node, vector<Node * > parents);
	void createPath(vector<Node * > path, Node * node,Node * lastnode, Node * commoancestor);


};