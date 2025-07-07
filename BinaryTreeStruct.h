#pragma once
#include <string>
#include <sstream>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;


    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};