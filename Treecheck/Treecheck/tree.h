#pragma once
#include "Structs.h"
#include <string>
#include <iostream>

class Tree
{
public:
    Tree();
    ~Tree();

    void read(struct::tnode* node);

    void add(int n);

    tnode* search(int n);

private:
    tnode* node;
};

