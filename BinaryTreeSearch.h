#pragma once
#include <iostream>
#include <string>
#include <cctype>

const char LOWER_CASE[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z', '\0' };
const int SIZE_LOWER_CASE = sizeof(LOWER_CASE) / sizeof(LOWER_CASE[0]);

//const char UPPER_CASE[] = { 'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'L', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Z', '\0' };

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
			subtree->m_value = std::tolower(value);
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
				result += " ";
				temp->is_visited = true;
				temp = head;
			}
		}
		return result;
	}
	
	//функція яка перевіряє чи char приголосний
	bool isConsonant(char c) {
		for (int i = 0; i < SIZE_LOWER_CASE; i++) {
			if (c == LOWER_CASE[i]) return true;
			else continue;
		}
		return false;
	}

	//пошук другої приголосної літери
	char secondConsonantLetter(struct Node* head) {
		int count = 0;
		
		if (head == nullptr) return '0';

		if (isConsonant(head->m_value)) {
			count++;

			if (count == 2) {
				return head->m_value;
			}
		}
		
		if (secondConsonantLetter(head->m_left)) return head->m_value;
		return secondConsonantLetter(head->m_right);
	}


};