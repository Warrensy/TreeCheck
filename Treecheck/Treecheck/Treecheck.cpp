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
// int main(int argc, char* argv[])

int main() 
{
    //std::string filename_tree, filename_subtree;
    Tree* tree = new Tree();

    //if (argc >= 2) {
    //    filename_tree = argv[1];
    //    if (!fillBSTfromFile(tree, filename_tree)) return 1;
    //}
    //else {
    //    std::cout << "treecheck: Missing filename, which contains numbers to fill the BST." << std::endl;
    //    return 1;
    //}
    //
    //if (argc == 3) {
    //    filename_subtree = argv[2];
    //    if (!fillBSTfromFile(subTree, filename_subtree)) return 1;
    //}
    
	return 0;
}

