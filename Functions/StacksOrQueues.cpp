#include "StacksOrQueues.h"
#include "MyStruct.h"
#include <sstream>
#include <ostream>
#include <ctime>

void StacksOrQueues::push(char ch)
{

    Node* newNode = new Node;
    newNode->symbol = ch;
    newNode->next = top;
    top = newNode;

}

char StacksOrQueues::pop()
{

    if (isEmpty()) {
        return '\0';
    }
    Node* temp = top;
    char ch = top->symbol;
    top = top->next;
    delete temp;
    return ch;

}

bool StacksOrQueues::isEmpty()
{
    return top == nullptr;
}

void StacksOrQueues::print()
{
    std::ostringstream oss;

    Node* current = top;
    while (current != nullptr) {
        oss << current->symbol;
        current = current->next;
    }
    oss << "\n";

}

std::string StacksOrQueues::generateRandomString(int length)
{
    srand(time(NULL));
    std::string result;
    for (int i = 0; i < length; i++) {
        char ch = 'a' + rand() % 26;
        result += ch;
    }
    return result;
}
