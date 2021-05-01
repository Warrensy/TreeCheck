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

    void read(std::string filePath = "null");

    void findAvgMinMax(tnode* node, int& minValue, int& maxValue, int& totalValue, int& nodesCount);

    void printTree(tnode* node);

    void addNode(tnode* node, int newKey);

    void deleteTree(tnode* node);

    tnode* superSearch(std::string nodeToFind);

    tnode* search(tnode* node, int n, std::vector<int>& path);

    int calcBalance(tnode* node);

    tnode* root;

private:

    //int maxValue, minValue, totalValue, nodesCount;

    bool isAVL;
};

