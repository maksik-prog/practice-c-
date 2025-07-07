#pragma once
#include "MyStruct.h"


class BinaryTree
{
private:

	Tree* root;

	bool searchValue(Tree* tree, int value);

	Tree* insertNode(Tree* tree, int value);

	int calculateDepth(Tree* tree);

	void printTreeWithLines(Tree* tree, string indent, bool isLast);

public:

	BinaryTree();

	~BinaryTree();

	void destroyTree(Tree* tree);

	bool insert(int value);

	int getDepth();

	void fillRandom(int count);

	void printTree();

	bool isEmpty();

	void showMenu();


};

