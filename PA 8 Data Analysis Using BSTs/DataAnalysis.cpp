#include "DataAnalysis.h"
DataAnalysis::DataAnalysis()
{
	//implicit
}

DataAnalysis::~DataAnalysis() //destructor just makes sure to close the fstream object
{
	dataStream.close();
}

void DataAnalysis::runAnalysis() //wrapper function that calls the functions down below
{
	openFile();
	loopThrough();
	findTrends();
}

bool DataAnalysis::openFile() //opens the csv file and then returns whether or not the file is open
{
	dataStream.open("data.csv", ios::in);
	return dataStream.is_open();
}

void DataAnalysis::readLine(string& units, string& type, string& transaction) //reads a single line from the csv, setting the references to the appropriate value in the line
{
	getline(dataStream, units, ',');
	getline(dataStream, type, ',');
	getline(dataStream, transaction);
}

void DataAnalysis::insertIntoTree(string units, string type, string transaction) //uses the values acquired from the readLine function to insert those values into the right tree
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

void DataAnalysis::loopThrough() //this function utilizes the two above functions to read through the entire csv file and then insert it into the tree, as well as printing each list after each read
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

void DataAnalysis::findTrends() //after reading in the file these go through each tree and print out the larges and smallest from each tree
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