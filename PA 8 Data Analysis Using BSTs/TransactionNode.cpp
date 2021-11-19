#include "TransactionNode.h"

TransactionNode::TransactionNode(string newData, int newUnits) : Node(newData)
{
	units = newUnits;
}

TransactionNode::~TransactionNode()
{
	//implicit
}

int TransactionNode::getUnits() const
{
	return units;
}

void TransactionNode::setUnits(int newUnits)
{
	units = newUnits;
}

void TransactionNode::printData()
{
	cout << " " << this->mData << " : " << this->units << " units." << endl;
}