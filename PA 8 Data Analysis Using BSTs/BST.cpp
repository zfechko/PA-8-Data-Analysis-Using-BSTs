#include "BST.h"


BST::BST()
{
	pRoot = nullptr;
}

BST::~BST()
{
	chopTree(pRoot);
}

void BST::chopTree(Node* pTree)
{
	if(pTree != nullptr)
	{
		chopTree(pTree->getLeft());
		chopTree(pTree->getRight());
		delete pTree;
	}
}

void BST::insert(string newData, int newUnits)
{
	TransactionNode* insertionNode = new TransactionNode(newData, newUnits);
	insert(dynamic_cast<TransactionNode*>(pRoot), insertionNode);
}

void BST::insert(TransactionNode* pTree, TransactionNode* newNode)
{
	if (pRoot == nullptr)
	{
		pRoot = newNode;
	}
	else
	{
		if (newNode->getUnits() < pTree->getUnits()) //if we need to go left
		{
			if (pTree->getLeft() == nullptr)
			{
				pTree->setLeft(newNode);
			}
			else
			{
				insert(dynamic_cast<TransactionNode*>(pTree->getLeft()), newNode);
			}
		}
		else if (newNode->getUnits() > pTree->getUnits()) // if we need to go to the right
		{
			if (pTree->getRight() == nullptr)
			{
				pTree->setRight(newNode);
			}
			else
			{
				insert(dynamic_cast<TransactionNode*>(pTree->getRight()), newNode);
			}
		}
		else
		{
			cout << "OOPS, THERE'S A DUPLICATE VALUE BEING ENTERED, THAT'S A NONO" << endl;
		}
	}
}

Node* BST::getRoot()
{
	return pRoot;
}

void BST::inOrderTraversal(Node* pTree)
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}