#pragma once
#include "Structs.h"
#include <string>
#include <iostream>

class Tree
{
public:
    Tree();
    ~Tree();

    void read();

    void findMax(::tnode* node, int sum, int max, int min, int count);

    void printTree(::tnode* node);

    void checkNode(::tnode* node, int newKey);

    tnode* search(int n);

    tnode* node;
private:
};

