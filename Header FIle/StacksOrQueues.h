#pragma once
#include "MyStruct.h"
#include <string>


class StacksOrQueues
{
private:
    Node* top;
public:
    StacksOrQueues() : top(nullptr) {}

    void push(char ch);

    char pop();

    bool isEmpty();

    void print();

    std::string generateRandomString(int length);

};

