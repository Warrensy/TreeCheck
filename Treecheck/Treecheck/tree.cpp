#include <fstream>
#include "tree.h"

Tree::Tree()
{
	this->isAVL = true;
	this->root = nullptr;
	read();

	std::string nodeToFind;
	do {
		std::cout << "Enter 'x' to skip.\n";
		std::cout << "Search: ";
		std::cin >> nodeToFind;
		superSearch(nodeToFind);
	} while (nodeToFind.compare("x") != 0);
}

Tree::~Tree()
{
	deleteTree(this->root);
}


// Rekursiv. Geht wenn möglich zuerst links ansonsten rechts.
void Tree::printTree(tnode* node)
{
	if (node->left != nullptr)
	{
		printTree(node->left);
	}
	if (node->right != nullptr)
	{
		printTree(node->right);
	}
	std::cout << "Note: " << node->key << std::endl;
}

// Rekursiv. Geht systematisch nach links oder rechts bis er eine Node einfügen kann.
void Tree::addNode(tnode* node, int newKey)
{
	if (newKey < node->key)
	{
		if (node->left == nullptr)
		{
			node->left = new tnode;
			node->left->key = newKey;
		}
		addNode(node->left, newKey);
	}
	if (newKey > node->key)
	{
		if (node->right == nullptr)
		{
			node->right = new tnode;
			node->right->key = newKey;
		}
		else
		{
		addNode(node->right, newKey);
		}
	}
}

void Tree::deleteTree(tnode* node)
{
	if (node->left != nullptr)
	{
		deleteTree(node->left);
	}
	if (node->right != nullptr)
	{
		deleteTree(node->right);
	}
	delete node;
}

tnode* Tree::superSearch(std::string nodeToFind)
{
	tnode* resultNode = nullptr;
	if (nodeToFind != "x")
	{
		std::vector<int> path;
		if ((resultNode = this->search(this->root, stoi(nodeToFind), path)) != nullptr)
		{
			std::cout << nodeToFind << " found ";
			for (int i = path.size() - 1; i >= 0; i--)
			{
				std::cout << path[i] << (i != 0 ? ", " : "\n");
			}
		}
		else
		{
			std::cout << nodeToFind << " Not Found" << std::endl;
		}
	}

	return resultNode;
}

// Ließt Baum aus .txt file aus.
void Tree::read(std::string filePath)
{
	std::string readText;
	int newKey = 0;
	if (filePath.compare("null") == 0) {
		std::cout << "Dateipfad für import: ";
		std::cin >> filePath;
	}
	std::fstream MyReadFile(filePath);
	
	// Für den ersten Knoten.
	getline(MyReadFile, readText);
	newKey = stoi(readText);
	this->root = new tnode;
	this->root->key = newKey;

	while (getline(MyReadFile, readText))
	{
		newKey = stoi(readText);
		addNode(this->root, newKey);
	}
	std::cout << std::endl << "Baum erfolgreich eingebunden" << std::endl;
	printTree(this->root);

	int minValue, maxValue, totalValue, nodesCount;
	minValue = maxValue = NULL;
	totalValue = nodesCount = 0;
	findAvgMinMax(this->root, minValue, maxValue, totalValue, nodesCount);
	std::cout << "Max: " << maxValue << std::endl;
	std::cout << "Min: " << minValue << std::endl;
	std::cout << "Avg: " << (float)totalValue/(float)nodesCount << std::endl;

	calcBalance(this->root);

	//std::cout << "Found:" << this->search(this->root, 100);

	MyReadFile.close();
}

void Tree::findAvgMinMax(::tnode* node, int& minValue, int& maxValue, int& totalValue, int& nodesCount)
{
	nodesCount++;
	totalValue += node->key;
	if (minValue == NULL && maxValue == NULL) {
		maxValue = node->key;
		minValue = node->key;
	}
	else {
		if (node->key > maxValue)
			maxValue = node->key;
		if (node->key < minValue)
			minValue = node->key;
	}

	if (node->left != nullptr)
	{
		findAvgMinMax(node->left, minValue, maxValue, totalValue, nodesCount);
	}
	if (node->right != nullptr)
	{
		findAvgMinMax(node->right, minValue, maxValue, totalValue, nodesCount);
	}

	return;
}



tnode* Tree::search(tnode* node, int n, std::vector<int>& path)
{
	tnode* left, * right;
	left = right = nullptr;
	
	if (n == node->key) {
		path.emplace_back(node->key);
		return node;
	}
	if (n < node->key)
	{
		if (node->left != nullptr) {
			left = search(node->left, n, path);
		}
	}
	if (n > node->key)
	{
		if (node->right != nullptr) {
			right = search(node->right, n, path);
		}
	}

	if (left != nullptr) {
		path.emplace_back(node->key);
		return left;
	}
	if (right != nullptr) {
		path.emplace_back(node->key);
		return right;
	}
	return nullptr;
}

//Berechnet die Balanz für jede Node, rekursiv
int Tree::calcBalance(tnode* node)
{
	int bal, balLeft, balRight;
	bal = balLeft = balRight = 0;
	if (node->left != nullptr)
	{
		balLeft = calcBalance(node->left);
	}
	if (node->right != nullptr)
	{
		balRight = calcBalance(node->right);
	}
	bal = balRight - balLeft; //links ist hierbei die "negative" Balanz
	std::cout << "bal(" << node->key << ") = " << bal << (bal < -1 || bal > 1 ? " (AVL violation!)" : "") << "\n";
	bal < -1 || bal > 1 ? this->isAVL = false : false;

	if (node->right == nullptr && node->left == nullptr) { //Blattknoten
		return 1;
	}
	else {
		return 1 + (balRight > balLeft ? balRight : balLeft); //die drüberliegende Node interessiert nur der längere Zweig
	}
}
