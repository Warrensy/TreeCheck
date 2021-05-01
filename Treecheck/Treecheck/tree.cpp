#include <fstream>
#include "tree.h"

Tree::Tree()
{
	this->minValue = NULL;
	this->maxValue = NULL;
	this->totalValue = this->nodesCount = 0;
	this->root = nullptr;
	read();

	std::string subTree;
	std::cout << "Enter 'x' to skip.";
	std::cout << "Search: ";
	std::cin >> subTree;
	if (subTree != "x")
	{
		if (this->search(this->root, stoi(subTree)) != nullptr)
		{
			std::cout << subTree << "found ";
			for (int i = this->searchPath.size()-1; i > 0; i--)
			{
				std::cout << this->searchPath[i] << ",";
			}
		}
		else
		{
			std::cout << subTree << "Not Found" << std::endl;
		}
		this->search(this->root, stoi(subTree));
	}
}

Tree::~Tree()
{

}


// Rekursiv. Geht wenn mˆglich zuerst links ansonsten rechts.
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

// Rekursiv. Geht systematisch nach links oder rechts bis er eine Node einf¸gen kann.
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

// Lieﬂt Baum aus .txt file aus.
void Tree::read()
{
	std::string readText, filePath;
	int newKey = 0;
	std::cout << "Dateipfad f¸r import: ";
	std::cin >> filePath;
	std::fstream MyReadFile(filePath);
	
	// F¸r den ersten Knoten.
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

	this->findAvgMinMax(this->root);
	std::cout << "Max: " << this->maxValue << std::endl;
	std::cout << "Min: " << this->minValue << std::endl;
	std::cout << "Avg: " << this->totalValue/this->nodesCount << std::endl;

	this->calcBalance(this->root);

	//std::cout << "Found:" << this->search(this->root, 100);

	MyReadFile.close();
}

void Tree::findAvgMinMax(::tnode* node)
{
	this->nodesCount++;
	this->totalValue += node->key;
	if (this->minValue == NULL && this->maxValue == NULL) {
		this->maxValue = node->key;
		this->minValue = node->key;
	}
	else {
		if (node->key > this->maxValue)
			this->maxValue = node->key;
		if (node->key < this->minValue)
			this->minValue = node->key;
	}

	if (node->left != nullptr)
	{
		this->findAvgMinMax(node->left);
	}
	if (node->right != nullptr)
	{
		this->findAvgMinMax(node->right);
	}

	return;
}

tnode* Tree::search(tnode* node, int n)
{
	tnode* left, * right;
	left = right = nullptr;
	
	if (n == node->key) {
		this->searchPath.emplace_back(node->key);
		return node;
	}
	if (n < node->key)
	{
		if (node->left != nullptr) {
			left = this->search(node->left, n);
		}
	}
	if (n > node->key)
	{
		if (node->right != nullptr) {
			right = this->search(node->right, n);
		}
	}
	if (left != nullptr) {
		this->searchPath.emplace_back(node->key);
		return left;
	}
	if (right != nullptr) {
		this->searchPath.emplace_back(node->key);
		return right;
	}
	return nullptr;
}

int Tree::calcBalance(tnode* node)
{
	int bal, balLeft, balRight;
	bal = balLeft = balRight = 0;
	if (node->left != nullptr)
	{
		balLeft = this->calcBalance(node->left);
	}
	if (node->right != nullptr)
	{
		balRight = this->calcBalance(node->right);
	}
	bal = balRight - balLeft;
	std::cout << "bal(" << node->key << ") = " << bal << (bal < -1 || bal > 1 ? " (AVL violation!)" : "") << "\n";

	if (node->right == nullptr && node->left == nullptr) { //Blattknoten
		return 1;
	}
	else {
		return 1 + (balRight > balLeft ? balRight : balLeft);
	}
}
