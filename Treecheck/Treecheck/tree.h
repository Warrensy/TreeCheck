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

    void read(std::string filePath, std::string subTreePath);                                           //O(n* log n + m * log m + m * log n) || Aufruf von findAvgMinMax, addNode *n, calcBalance, subTreeSearch, deleteTree

    void findAvgMinMax(tnode* node, int& minValue, int& maxValue, int& totalValue, int& nodesCount);    //O(n)

    void addNode(tnode* node, int newKey);                                                              //O(log n)

    void deleteTree(tnode* node);                                                                       //O(n)

    tnode* superSearch(std::string nodeToFind);                                                         //O(log n)

    tnode* search(tnode* node, int n, std::vector<int>& path);                                          //O(log n)

    int calcBalance(tnode* node);                                                                       //O(n)

    tnode* root;

    bool subTreeSearch(tnode* sub, tnode* parent = nullptr);                                            //O(m* log n)

    tnode* nodeSearch(tnode* root, int n);                                                              //O(log n)

private:

    //int maxValue, minValue, totalValue, nodesCount;

    bool isAVL;
};

