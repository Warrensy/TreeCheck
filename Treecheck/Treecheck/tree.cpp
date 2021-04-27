#include <fstream>
#include "tree.h"

Tree::Tree()
{
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
	std::cout << "Max: " << findMax(root, 0) << std::endl;
	std::cout << "Min: " << findMin(root, 1000) << std::endl;
	std::cout << "Avg: " << findAvg(root, 0, 0) << std::endl;
	MyReadFile.close();
}

int Tree::findMin(::tnode* node, int min)
{
	if (node->key < min) { min = node->key; }
	if (node->left != nullptr)
	{
		if (min > findMin(node->left, min))
		{
			min = findMin(node->left, min);
		}
	}
	if (node->right != nullptr)
	{
		if (min > findMin(node->right, min))
		{
			min = findMin(node->right, min);
		}
	}
	return min;

}

int Tree::findMax(::tnode* node, int max)
{
	if (node->key > max) { max = node->key; }
	if (node->left != nullptr)
	{
		if (max < findMax(node->left, max))
		{
			max = findMax(node->left, max);
		}
	}
	if (node->right != nullptr)
	{
		if (max < findMax(node->right, max))
		{
			max = findMax(node->right, max);
		}
	}
	return max;
}

int Tree::findAvg(::tnode* node, float sum, int count)
{
	count++;
	sum += node->key;
	if (node->left != nullptr)
	{
		sum = findAvg(node->left, sum, count)*(count+1);
	}
	if (node->right != nullptr)
	{
		sum = findAvg(node->left, sum, count) * (count + 1);
	}
	
	return sum/count;
}

tnode* Tree::search(int n)
{
	return nullptr;
}
