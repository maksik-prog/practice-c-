#include "LinkedLists.h"
#include <sstream>
#include <ostream>
#include "MyStruct.h"
#include <iostream>
#include <ctime>

void LinkedLists::addNode(Node*& head, int value)
{
    if (head == nullptr) {
        head = createNode(value);
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = createNode(value);
    }
}

Node* LinkedLists::createNode(int value)
{
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

void LinkedLists::printList(Node* head)
{
    std::ostringstream oss;

    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data;
        if (current->next != nullptr) {
            std::cout << " - ";
        }
        current = current->next;
    }
    std::cout << "\n";
}

void LinkedLists::reverse(Node*& head, int k)
{

    int length = 0;
    Node* current = head;
    while (current != nullptr) {
        length++;
        current = current->next;
    }

    int pos = length - k;
    current = head;
    for (int i = 1; i < pos; i++) {
        if (current->next == nullptr) {
            break;
        }
        current = current->next;
    }

    Node* prev = nullptr;
    Node* next = nullptr;
    Node* reflectStart = (pos == 0) ? head : current->next;

    if (pos > 0) {
        current->next = nullptr;
    }

    current = reflectStart;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    reflectStart = prev;

    if (pos > 0) {
        current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = reflectStart;
    }
    else {
        head = reflectStart; 
    }
}

void LinkedLists::fillRandom(Node*& head, int count)
{

    srand(time(NULL));
    for (int i = 0; i < count; i++) {
        addNode(head, rand() % 100 + 1);
    }

}
