#include <fstream>
#include "tree.h"

Tree::Tree(std::string filename)
{
	this->minValue = NULL;
	this->maxValue = NULL;
	this->totalValue = this->nodesCount = 0;
	read();
}

Tree::~Tree()
{

}


// Rekursiv. Geht wenn mˆglich zuerst links ansonsten rechts.
void Tree::printTree(::tnode* node)
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
void Tree::checkNode(::tnode* node, int newKey)
{
	if (newKey < node->key)
	{
		if (node->left == nullptr)
		{
			node->left = new tnode;
			node->left->key = newKey;
		}
		checkNode(node->left, newKey);
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
		checkNode(node->right, newKey);
		}
	}
}

// Lieﬂt Baum aus .txt file aus.
void Tree::read()
{
	tnode* node = nullptr;
	tnode* root = nullptr;
	std::string readText, filePath;
	int newKey = 0;
	std::cout << "Dateipfad f¸r import: ";
	std::cin >> filePath;
	std::fstream MyReadFile(filePath);
	
	// F¸r den ersten Knoten.
	getline(MyReadFile, readText);
	newKey = stoi(readText);
	node = new tnode;
	node->key = newKey;
	root = node;
	while (getline(MyReadFile, readText))
	{
		newKey = stoi(readText);
		checkNode(root, newKey);
	}
	std::cout << std::endl << "Baum erfolgreich eingebunden" << std::endl;
	printTree(root);
	/*std::cout << "Max: " << findMax(root, 0) << std::endl;
	std::cout << "Min: " << findMin(root, 1000) << std::endl;
	std::cout << "Avg: " << findAvg(root, 0, 0) << std::endl;*/

	this->findAvgMinMax(root);
	std::cout << "Max: " << this->maxValue << std::endl;
	std::cout << "Min: " << this->minValue << std::endl;
	std::cout << "Avg: " << this->totalValue/this->nodesCount << std::endl;

	int min, max, sum, count;
	min = max = NULL;
	sum = count = 0;

	this->findAvgMinMaxAlt(root, min, max, sum, count);
	std::cout << "Max: " << max << std::endl;
	std::cout << "Min: " << min << std::endl;
	std::cout << "Avg: " << sum/count << std::endl;

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

tnode* Tree::search(int n)
{
	return nullptr;
}
