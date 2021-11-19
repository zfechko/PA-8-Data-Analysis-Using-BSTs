#include "BST.h"


BST::BST()
{
	pRoot = nullptr;
}

BST::~BST()
{
	chopTree(pRoot);
}

void BST::chopTree(Node* pTree) //destroyTree function, uses post order traversal to delete every node in the tree
{
	if(pTree != nullptr)
	{
		chopTree(pTree->getLeft());
		chopTree(pTree->getRight());
		delete pTree;
	}
}

void BST::insert(string newData, int newUnits) //public insert function takes the parameters to make a Transaction node
{
	TransactionNode* insertionNode = new TransactionNode(newData, newUnits); //creates transaction node with the parameters
	insert(dynamic_cast<TransactionNode*>(pRoot), insertionNode); //calls the private insert using a dynamic cast
}

//private insert function, this ond does all the leg work to insert a node in the right place
void BST::insert(TransactionNode* pTree, TransactionNode* newNode)
{
	if (pRoot == nullptr) //empty tree
	{
		setRoot(newNode);
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
		else //protection against invalid values (which won't happen in this assignment but it's nice to have
		{
			cout << "OOPS, THERE'S A DUPLICATE VALUE BEING ENTERED, THAT'S A NONO" << endl;
		}
	}
}

Node* BST::getRoot()
{
	return pRoot;
}

void BST::setRoot(Node* newRoot)
{
	pRoot = newRoot;
}

//prints all the data from least to greatest using in order traversal, this is the private function that doers all the leg work
void BST::inOrderTraversal(Node* pTree) 
{
	if (pTree != nullptr)
	{
		inOrderTraversal(pTree->getLeft());
		pTree->printData();
		inOrderTraversal(pTree->getRight());
	}
}

//public function that calls the private helper
void BST::inOrderTraversal()
{
	inOrderTraversal(pRoot);
}

//function to find the smallest node in the tree, doesn't do any traversal, just goes all the way down the left branch until it reaches a null pointer
TransactionNode& BST::findSmallest()
{
	TransactionNode* traverser = dynamic_cast<TransactionNode*>(pRoot);
	while (traverser->getLeft() != nullptr)
	{
		traverser = dynamic_cast<TransactionNode*>(traverser->getLeft());
	}
	return *traverser;
}

//function to find the largest node in the tree, doesn't do any traversal, just goes all the way down the right branch until it finds a leaf
TransactionNode& BST::findLargest()
{
	TransactionNode* traverser = dynamic_cast<TransactionNode*>(pRoot);
	while (traverser->getRight() != nullptr)
	{
		traverser = dynamic_cast<TransactionNode*>(traverser->getRight());
	}
	return *traverser;
}