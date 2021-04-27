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

    tnode* search(int n);

private:
    tnode* root;
};

