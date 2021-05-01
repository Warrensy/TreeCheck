#pragma once
#include "Structs.h"
#include <string>
#include <iostream>
#include <vector>

class Tree
{
public:
    Tree();
    ~Tree();

    void read();

    void findAvgMinMax(tnode* node);

    void printTree(tnode* node);

    void addNode(tnode* node, int newKey);

    tnode* search(tnode* node, int n);

    int calcBalance(tnode* node);

    tnode* root;

private:

    std::vector<int> searchPath;

    int maxValue, minValue, totalValue, nodesCount;
};

