#include "Position.h"
#include "Door.h"


class Node
{
public:
	Node(Node* father, int width, int height, int x, int y);

	~Node();


	void setleftChild(Node * node);
	void setrightchild(Node * node);

	Node * getleftchild();
	Node * getrightchild();

	Position m_position;
	int m_width;
	int m_height;
	Door d;
	bool hasparentDoor;
	bool isvertical;

	Node * m_father;


private:
	Node * m_left_child;
	Node * m_right_child;


};

