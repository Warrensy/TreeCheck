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

    int findMax(::tnode* node, int max);

    int findAvg(::tnode* node, float sum, int count);

    void findAvgMinMax(::tnode* node);

    void findAvgMinMaxAlt(::tnode* node, int& min, int& max, int& sum, int& count);

    int findMin(::tnode* node, int min);

    void printTree(::tnode* node);

    void checkNode(::tnode* node, int newKey);

    tnode* search(int n);

    tnode* node;
private:

    int maxValue, minValue, totalValue, nodesCount;
};

