#pragma once
#include <iostream>

struct Node {
	char m_value;
	bool is_visited;
	Node* m_left;
	Node* m_right;
};


class BinaryTreeSearch {
private:
	Node* m_root;

public:
	BinaryTreeSearch() { m_root = nullptr; }

	//вставити значення у дерево
	void insertData(char value,struct Node*& subtree)
	{
		if (subtree == nullptr)
		{
			subtree = new Node();
			subtree->m_value = value;
		}
		else if (value < subtree->m_value) insertData(value, subtree->m_left);
		else insertData(value, subtree->m_right);
	}

	//пошук значення в дереві
	bool findData(struct Node* tree, char value) {
		if (tree == nullptr) return false;
		else if (tree->m_value == value) return true;
		else if (tree->m_value < value) return findData(tree->m_left, value);
		else return findData(tree->m_right, value);
	}

	//зворотній обхід дерева
	std::string postorder(struct Node* head)
	{
		std::string result = "";
		struct Node* temp = head;
		while (temp && temp->is_visited == false) {

			//обхід лівого дерева
			if (temp->m_left && temp->m_left->is_visited == false)
				temp = temp->m_left;

			//обхід правого дерева
			else if (temp->m_right && temp->m_right->is_visited == false)
				temp = temp->m_right;

			//після обходу is_visited = true
			else {
				result += temp->m_value;
				temp->is_visited = true;
				temp = head;
			}
		}
		return result;
	}
	
};