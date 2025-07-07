#pragma once
#include "MyStruct.h"

class LinkedLists
{
public:
    void addNode(Node*& head, int value);

    Node* createNode(int value);

        void printList(Node* head);

        void reverse(Node*& head, int k);

        void fillRandom(Node*& head, int count);
};

