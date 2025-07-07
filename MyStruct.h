#pragma once
#include <string>
#include <sstream>

using namespace std;

struct Node {
    int data;
    char symbol;
    Node* next;  
};

struct Abonent {
    string fio;
    string address;
    string phone;
};

struct Speaking {
    string phone;      
    int time;          
    double price;      
};

struct Tree {
    int data;          
    Tree* left;       
    Tree* right;       

    Tree(int value) {
        data = value;
        left = nullptr;  
        right = nullptr;
    }
};