#pragma once

struct tnode
{
    int key;
    struct tnode* left = nullptr;
    struct tnode* right = nullptr;
};
