#include "Node.h"

Node::Node(string newData)
{
	mData = newData;
	pLeft = nullptr;
	pRight = nullptr;
}

Node::~Node()
{
	//implicit
}

string Node::getData() const
{
	return this->mData;
}

Node* Node::getLeft() const
{
	return this->pLeft;
}

Node* Node::getRight() const
{
	return this->pRight;
}

void Node::setData(string newData)
{
	mData = newData;
}

void Node::setLeft(Node* newNode)
{
	this->pLeft = newNode;
}

void Node::setRight(Node* newNode)
{
	this->pRight = newNode;
}