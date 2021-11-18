#pragma once
#include "Node.h"
class TransactionNode :
    public Node
{
private:
    int units;

public:
    TransactionNode(string newData = "", int newUnits = 0);
    ~TransactionNode();

    int getUnits() const;
    void setUnits(int newUnits);
    void printData();
};

