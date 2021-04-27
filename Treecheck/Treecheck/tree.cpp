#include <fstream>
#include "tree.h"

Tree::Tree()
{
	this->node = new tnode;
	read(node);
}

Tree::~Tree()
{

}

void Tree::read(::tnode* node)
{
	std::string readText, filePath;
	int newNumber = 0;
	std::cout << "Dateipfad für import: ";
	std::cin >> filePath;
	std::fstream MyReadFile(filePath);
	while (getline(MyReadFile, readText))
	{
		newNumber = stoi(readText);
		if(newNumber == node->key) {}
		else if (newNumber < node->key)
		{
			if (node->left != NULL)
			{

			}
		}
		else if (newNumber > node->key)
		{

		}
	}
}



void Tree::add(int n)
{

}

tnode* Tree::search(int n)
{
	return nullptr;
}
