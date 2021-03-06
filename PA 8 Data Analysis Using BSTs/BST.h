#pragma once
#include "TransactionNode.h"

class BST
{
private:
	Node* pRoot;
	void chopTree(Node* pTree);
	void insert(TransactionNode* pTree, TransactionNode* newNode);
	void inOrderTraversal(Node* pTree);

public:
	BST();
	~BST();

	Node* getRoot();
	void setRoot(Node* newRoot);
	void insert(string newData, int newUnits);
	void inOrderTraversal();

	TransactionNode& findSmallest();
	TransactionNode& findLargest();
};

