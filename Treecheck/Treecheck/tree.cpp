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
	//findMax(root, 0, 0, 1000, 0);
	MyReadFile.close();
}

//void Tree::findMax(::tnode* node, int sum, int max, int min, int count)
//{
//	count++;
//	sum += node->key;
//	if (node->key < min) { min = node->key; }
//	if (node->key > max) { max = node->key; }
//	if (node->left != nullptr)
//	{
//		findMax(node->left, sum, max, min, count);
//	}
//	if (node->right != nullptr)
//	{
//		findMax(node->left, sum, max, min, count);
//	}
//	if(node->left == nullptr && node->right == nullptr)
//	{
//		std::cout << "MIN Value: " << min << std::endl;
//		std::cout << "MAX Value: " << max << std::endl;
//		std::cout << "AVG Value: " << sum/count << std::endl;
//	}
//}

tnode* Tree::search(int n)
{
	return nullptr;
}
