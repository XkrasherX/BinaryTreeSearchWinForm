#pragma once
#include <iostream>

class Node {

public:
	Node(char value) {
		m_value = value;
		m_left = nullptr;
		m_right = nullptr;
	}

	char m_value;
	Node* m_left;
	Node* m_right;
};

class BinaryTreeSearch {
private:
	Node* m_root;

public:
	BinaryTreeSearch() { m_root = nullptr; }

	void insertData(char value, Node*& subtree)
	{
		if (subtree == nullptr)
		{
			subtree = new Node(value);
		}
		else if (value < subtree->m_value)
		{
			insertData(value, subtree->m_left);
		}
		else
		{
			insertData(value, subtree->m_right);
		}
	}
};