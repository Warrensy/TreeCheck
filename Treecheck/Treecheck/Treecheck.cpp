// Treecheck.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>

struct tnode
{
    int key;
    struct tnode* left;
    struct tnode* right;
};

void readTree()
{
    std::string filePath;
    std::cout << "Dateipfad für import: ";
    std::cin >> filePath;
}

int main()
{
    std::cout << "Hello World!\n";
    std::cout << "Hi!";
}

