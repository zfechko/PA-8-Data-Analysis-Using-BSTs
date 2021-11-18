#pragma once
#include "libraries.h"

class Node
{
protected:
	string mData;
	Node* pLeft;
	Node* pRight;

public:
	Node(string newData = "");
	virtual ~Node();
	void setData(string newData);
	void setLeft(Node* newNode);
	void setRight(Node* newNode);

	string getData() const;
	Node* getLeft() const;
	Node* getRight() const;

	virtual void printData() = 0; //pure virtual
};

