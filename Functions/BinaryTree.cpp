#include "BinaryTree.h"
#include "MyStruct.h"
#include "iostream"
#include "ostream"
#include "sstream"
#include <ctime>

using namespace std;


bool BinaryTree::searchValue(Tree* tree, int value)
{
    if (tree == nullptr) {
        return false;
    }

    if (tree->data == value) {
        return true;
    }

    if (value < tree->data) {
        return searchValue(tree->left, value);
    }
    else {
        return searchValue(tree->right, value);
    }
}

Tree* BinaryTree::insertNode(Tree* tree, int value)
{
    if (tree == nullptr) {
        return new Tree(value);
    }

    if (value < tree->data) {
        tree->left = insertNode(tree->left, value);
    }
    else {
        tree->right = insertNode(tree->right, value);
    }

    return tree;
}

int BinaryTree::calculateDepth(Tree* tree)
{
    if (tree == nullptr) {
        return 0;
    }

    int leftDepth = calculateDepth(tree->left);
    int rightDepth = calculateDepth(tree->right);

    int maxDepth = (leftDepth > rightDepth) ? leftDepth : rightDepth;
    return 1 + maxDepth;
}

void BinaryTree::printTreeWithLines(Tree* tree, string indent, bool isLast)
{

    if (tree == nullptr) return;

    cout << indent;
    if (isLast) {
        cout << "|__ ";
        indent += "    ";
    }
    else {
        cout << "|-- ";
        indent += "|   ";
    }
    cout << tree->data << "\n";

    bool hasLeft = (tree->left != nullptr);
    bool hasRight = (tree->right != nullptr);

    if (hasLeft && hasRight) {
        printTreeWithLines(tree->left, indent, false);
        printTreeWithLines(tree->right, indent, true);
    }
    else if (hasLeft) {
        printTreeWithLines(tree->left, indent, true);
    }
    else if (hasRight) {
        printTreeWithLines(tree->right, indent, true);
    }

}

BinaryTree::BinaryTree()
{

    root = nullptr;

}

BinaryTree::~BinaryTree()
{

    destroyTree(root);

}

void BinaryTree::destroyTree(Tree* tree)
{

    if (tree != nullptr) {
        destroyTree(tree->left);
        destroyTree(tree->right);
        delete tree;
    }

}

bool BinaryTree::insert(int value)
{
    if (searchValue(root, value)) {
        cout << "����� " << value << " ��� ���������� � ������!\n";
        return false;
    }

    root = insertNode(root, value);
    cout << "��������� �����: " << value << "\n";
    return true;
}

int BinaryTree::getDepth()
{
    return calculateDepth(root);
}

void BinaryTree::fillRandom(int count)
{

    cout << "��������� ������ " << count << " ����������� ���������� �������:\n";
    int attempts = 0;
    int added = 0;

    while (added < count && attempts < count * 10) { 
        int randomNum = (rand() % 100) + 1;  
        if (insert(randomNum)) {
            added++;
        }
        attempts++;
    }

    if (added < count) {
        cout << "������� �������� ������ " << added << " ���������� �����.\n";
    }


}

void BinaryTree::printTree()
{

    cout << "\n=== ��������� ������ ===\n";
    if (root == nullptr) {
        cout << "������ ������\n";
        return;
    }

    printTreeWithLines(root, "", true);
    cout << "========================\n";

}

bool BinaryTree::isEmpty()
{
    return root == nullptr;
}

void BinaryTree::showMenu()
{

    cout << "\n=== ���� ===\n";
    cout << "������� ����� 1, ����� �������� �����\n";
    cout << "������� ����� 2, ����� �������� �������\n";
    cout << "������� ����� 3, ����� �������� ��������� �����\n";
    cout << "������� ����� 4, ����� �����\n";
    cout << "��� �����: ";

}

