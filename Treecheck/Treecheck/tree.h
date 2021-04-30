#pragma once
#include "Structs.h"
#include <string>
#include <iostream>

class Tree
{
public:
    Tree(std::string filename);
    ~Tree();

    void read();

    void findAvgMinMax(tnode* node);

    void findAvgMinMaxAlt(tnode* node, int& min, int& max, int& sum, int& count);

    void printTree(tnode* node);

    void addNode(tnode* node, int newKey);

    tnode* search(tnode* node, int n);

    int calcBalance(tnode* node);

    tnode* root;
private:

    int maxValue, minValue, totalValue, nodesCount;
};

