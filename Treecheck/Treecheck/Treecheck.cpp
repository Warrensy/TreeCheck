// FH Technikum 
// ALGOS SS21 
// BIF C2
// Bilicky Lukas & Dorian Fetty

#include <iostream>
#include <fstream>
#include "tree.h"


// argc         number of command line arguments
// argv         array of command line arguments
// argv[0]      is alway the absolute filename of the running program
// argv[1]      should be a filename, which contains numbers in each line to fill the BST
// argv[2]      should be a filename, which contains a subtree to search in the original BST

int main(int argc, char* argv[])
{
    std::string treePath, subTreePath;
    if (argc == 1)
    {
        std::cout << "Missing Tree-File.";
    }
    else if (argc == 2)
    {
        treePath = argv[1];
        subTreePath = "x";
        Tree* tree = new Tree(treePath, subTreePath);
    }
    else if (argc == 3)
    {
        treePath = argv[1];
        subTreePath = argv[2];
        Tree* tree = new Tree(treePath, subTreePath);
    }
    else
    {
        std::cout << "Tree path: ";
        std::cin >> treePath;
        std::cout << "\nSubtree path: ";
        std::cin >> subTreePath;
        Tree* tree = new Tree(treePath, subTreePath);
    }
    
	return 0;
}

