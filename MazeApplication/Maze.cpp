#include "stdafx.h"
#include "Maze.h"
#include <ctime>

#include <thread>         // std::this_thread::sleep_for
#include <chrono>     



#include "svg.h"

using namespace std;
ofstream  *myfile;

void Maze::Create_Maze(int width, int height) {
	printf("Creating the maze");

   
	srand(time(NULL)); // Seed the time


	Node * node = new Node(NULL, width, height,10,10);
	tree.InsertNewNode(node);
	node->isvertical = false;
	node->hasparentDoor = false;

	dividenode(node);

	
}

void Maze::dividenode(Node * node) {

	if (node->m_height > minimum || node->m_width > minimum) {// cut vertically 

		if (node->m_width > node->m_height ) {// we check the shortest edge of the node 

			int finalNum = rand() % (node->m_width - minimum) + minimum; // Generate the numberbetween minimum and width of the space, assign to variable.
			cout << " vertical :" << finalNum << " : " << node->m_position.x << endl;



			/*LEFT OF THE CUT  */
			Node * node1 = new Node(node, finalNum, node->m_height, node->m_position.x, node->m_position.y);
			
			node->setleftChild(node1); 
			tree.InsertNewNode(node1);



			//CHOOSE THE POSITION OF THE DOOR 

			node1->d.p1.x = node1->m_position.x + finalNum;
			node1->d.p1.y = node1->m_position.y + rand() % (node1->m_height - 0) + 0;
			node1->d.p2.x = node1->d.p1.x;
			node1->d.p2.y = node1->d.p1.y + minimum;// we make the door the size of the minimum of the size of a node

			node1->isvertical = true;
			if (node1->m_position.x > node->d.p1.x) {
				node1->hasparentDoor = false;
			}
			else {
				node1->hasparentDoor = true;
			}


			dividenode(node1);


			/*RIGHT OF THE CUT */
			Node * node2 = new Node(node, node->m_width-finalNum, node->m_height, node->m_position.x + finalNum, node->m_position.y);
			
			node->setrightchild(node2);
			tree.InsertNewNode(node2);

			//CHOOSE THE POSITION OF THE DOOR 
			node2->d.p1.y = node1->d.p1.y;
			node2->d.p1.x = node1->d.p1.x;
			node2->d.p2.x = node1->d.p2.x;
			node2->d.p2.y = node1->d.p2.y;

			node2->isvertical = true;
			if (node2->m_position.x > node->d.p1.x) {
				node2->hasparentDoor = false;
			}
			else {
				node2->hasparentDoor = true;
			}


			dividenode(node2);

			




		}
		else {										//CUT VERTICALLY

			int finalNum = rand() % (node->m_height - minimum) + minimum; // Generate the numberbetween minimum and height of the space, assign to variable.
			cout <<"Horizontal :" << finalNum << " : " << node->m_position.y << endl;

			//TOP OF THE CUT 
			Node * node3 = new Node(node, node->m_width, finalNum, node->m_position.x, node->m_position.y);
			
			node->setleftChild(node3);
			tree.InsertNewNode(node3);


			node3->d.p1.y = node3->m_position.y + finalNum;
			node3->d.p1.x = node3->m_position.x + rand() % (node3->m_width - 0) + 0;
			node3->d.p2.y = node3->d.p1.y;
			node3->d.p2.x = node3->d.p1.x + minimum;// we make the door the size of the minimum of the size of a node


			node3->isvertical = false;

			dividenode(node3);



			//BOTTOM OF THE CUT 

			Node * node4 = new Node(node, node->m_width, node->m_height- finalNum, node->m_position.x, node->m_position.y + finalNum);


			node->setrightchild(node4);
			tree.InsertNewNode(node4);


			node4->isvertical = false;

			node4->d.p1.y = node3->d.p1.y;
			node4->d.p1.x = node3->d.p1.x;
			node4->d.p2.y = node3->d.p2.y;
			node4->d.p2.x = node3->d.p2.x;// we make the door the size of the minimum of the size of a node

			dividenode(node4);

			
		}
	}
		
}


void Maze::printTheMaze() {

	ofstream  *myfile = new ofstream();
	myfile->open("test1.svg");

	svg_header(myfile , 600, 600);
	
	for (int i = 0; i < tree.tree.size(); i++) {
			svg_rect(myfile, tree.tree[i]->m_position.x, tree.tree[i]->m_position.y, tree.tree[i]->m_width, tree.tree[i]->m_height);
	}
	

	svg_footer(myfile);

	myfile->close();



}

void Maze::solver() {



}

void Maze::Draw() {

	myfile = new ofstream();
	myfile->open("test1.svg");
	svg_header(myfile, 3500, 3500);


	for (int i = 0; i < tree.tree.size(); i++) {
		if (i == 0) {
			svg_rect(myfile, tree.tree[i]->m_position.x, tree.tree[i]->m_position.y, tree.tree[i]->m_width, tree.tree[i]->m_height);
		}

		else if (tree.tree[i]->isvertical) {

			svg_line(myfile, tree.tree[i]->d.p1.x, tree.tree[i]->d.p1.y, tree.tree[i]->d.p1.x, tree.tree[i]->m_position.y);//vertical  line to the door


			svg_line(myfile, tree.tree[i]->d.p2.x, tree.tree[i]->d.p2.y, tree.tree[i]->d.p2.x, tree.tree[i]->m_position.y + tree.tree[i]->m_height);//vertical  line from the door to the top

		}
		else {

			svg_line(myfile, tree.tree[i]->d.p1.x, tree.tree[i]->d.p1.y, tree.tree[i]->m_position.x, tree.tree[i]->d.p1.y);//horizontal  line to the door


			svg_line(myfile, tree.tree[i]->d.p2.x, tree.tree[i]->d.p2.y, tree.tree[i]->m_position.x + tree.tree[i]->m_width, tree.tree[i]->d.p2.y);//horizontal  line from the door to the top

		}




	}
	svg_footer(myfile);
	myfile->close();
	
}



