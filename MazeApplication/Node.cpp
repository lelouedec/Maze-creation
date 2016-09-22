#include "stdafx.h"
#include "Node.h"


Node::Node(Node* father,int width, int height,int x, int y)
{
	m_father = father;
	m_width = width;
	m_height = height;
	m_position.x = x;
	m_position.y = y;
}


Node::~Node()
{


}

void Node::setleftChild(Node * node) {

	m_left_child = node;

}

void Node::setrightchild(Node * node){
	m_right_child = node;

}

Node * Node::getleftchild()
{
	return m_left_child;
}

Node * Node::getrightchild()
{
	return m_right_child;
}
