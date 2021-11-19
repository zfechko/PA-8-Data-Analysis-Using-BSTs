#include "DataAnalysis.h"
DataAnalysis::DataAnalysis()
{
	//implicit
}

DataAnalysis::~DataAnalysis()
{
	dataStream.close();
}

void DataAnalysis::runAnalysis()
{
	openFile();
	loopThrough();
	findTrends();
}

bool DataAnalysis::openFile()
{
	dataStream.open("data.csv", ios::in);
	return dataStream.is_open();
}

void DataAnalysis::readLine(string& units, string& type, string& transaction)
{
	getline(dataStream, units, ',');
	getline(dataStream, type, ',');
	getline(dataStream, transaction);
}

void DataAnalysis::insertIntoTree(string units, string type, string transaction)
{
	if (transaction == "Purchased")
	{
		purchasedTree.insert(type, stoi(units));
	}
	else if (transaction == "Sold")
	{
		soldTree.insert(type, stoi(units));
	}
}

void DataAnalysis::loopThrough()
{
	string units, type, transaction;
	while (!dataStream.eof())
	{
		readLine(units, type, transaction);
		insertIntoTree(units, type, transaction);
		cout << "[PURCHASED ITEMS]" << endl;
		purchasedTree.inOrderTraversal();
		cout << endl;
		cout << "[SOLD ITEMS]" << endl;
		soldTree.inOrderTraversal();
		cout << endl;
	}
}

void DataAnalysis::findTrends()
{
	cout << "[ITEM TRENDS]" << endl;
	cout << "[PURCHASED TRENDS]" << endl;
	cout << "Smallest: ";
	purchasedTree.findSmallest().printData();
	cout << "Largest: ";
	purchasedTree.findLargest().printData();
	cout << endl;
	cout << "[SOLD TRENDS]" << endl;
	cout << "Smallest: ";
	soldTree.findSmallest().printData();
	cout << "Largest: ";
	soldTree.findLargest().printData();
	cout << endl;
}