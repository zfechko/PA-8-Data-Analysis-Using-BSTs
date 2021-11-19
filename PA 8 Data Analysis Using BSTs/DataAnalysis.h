#pragma once
#include "BST.h"
class DataAnalysis
{
private:
	BST soldTree;
	BST purchasedTree;
	ifstream dataStream;

	bool openFile();

	void readLine(string& units, string& type, string& transaction);
	void insertIntoTree(string units, string type, string transaction);
	void loopThrough();
	void findTrends();
public:
	DataAnalysis();
	~DataAnalysis();

	void runAnalysis();
};

