#pragma once
class tree
{
    public:
        struct tnode
        {
            short balance;
            int key;
            struct tnode* left;
            struct tnode* right;
            struct tnode* parent;
        };

};

