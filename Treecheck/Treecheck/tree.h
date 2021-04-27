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

    void add(int n);

    void printTree(::tnode* node);

    tnode* search(int n);

    tnode* node;
private:
};

