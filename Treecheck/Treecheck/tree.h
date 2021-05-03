#pragma once
#include "Structs.h"
#include <string>
#include <iostream>
#include <vector>

class Tree
{
public:
    Tree(std::string treePath, std::string subTreePath);
    ~Tree();

    void read(std::string filePath, std::string subTreePath);

    void findAvgMinMax(tnode* node, int& minValue, int& maxValue, int& totalValue, int& nodesCount);

    void addNode(tnode* node, int newKey);

    void deleteTree(tnode* node);

    tnode* superSearch(std::string nodeToFind);

    tnode* search(tnode* node, int n, std::vector<int>& path);

    int calcBalance(tnode* node);

    tnode* root;

    bool subTreeSearch(tnode* sub, tnode* parent = nullptr);

    tnode* nodeSearch(tnode* root, int n);

private:

    //int maxValue, minValue, totalValue, nodesCount;

    bool isAVL;
};

