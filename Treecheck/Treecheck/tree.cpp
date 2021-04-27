#include <fstream>
#include "tree.h"

Tree::Tree()
{
	read();
}

Tree::~Tree()
{

}

// Rekursiver aufruf. Geht wenn möglich zuerst links ansonsten rechts.
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

// Ließt Baum aus .txt file aus.
void Tree::read()
{
	tnode* node = nullptr;
	tnode* tmp = nullptr;
	std::string readText, filePath;
	int newNumber = 0;
	std::cout << "Dateipfad für import: ";
	std::cin >> filePath;
	std::fstream MyReadFile(filePath);
	
	// Für den ersten Knoten.
	getline(MyReadFile, readText);
	newNumber = stoi(readText);
	node = new tnode;
	node->key = newNumber;
	tmp = node;
	// Alle folge-Knoten < aktueller-Knoten gehen links | folge-Knoten > aktueller-Knoten gehen rechts
	while (getline(MyReadFile, readText))
	{
		newNumber = stoi(readText);
		if (newNumber < node->key)
		{
			if (node->left != nullptr)
			{
				node = node->left;
				continue;
			}
			else
			{
				node->left = new tnode;
				node->left->key = newNumber;
			}
		}
		else if (newNumber > node->key)
		{
			if (node->right != nullptr)
			{
				node = node->right;
				continue;
			}
			else
			{
				node->right = new tnode;
				node->right->key = newNumber;
			}
		}
	}
	std::cout << std::endl << "Baum erfolgreich eingebunden" << std::endl;
	printTree(tmp);
	MyReadFile.close();
}



void Tree::add(int n)
{

}

tnode* Tree::search(int n)
{
	return nullptr;
}
