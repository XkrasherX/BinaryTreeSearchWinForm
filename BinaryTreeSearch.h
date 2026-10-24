#pragma once
#include <iostream>
#include <string>
#include <cctype>

const char LOWER_CASE[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z', '\0' };
const int SIZE_LOWER_CASE = sizeof(LOWER_CASE) / sizeof(LOWER_CASE[0]);

//структура вершини
struct Node {
	char m_value;
	bool is_visited;
	Node* m_left;
	Node* m_right;
};

//клас для бінарного дерева пошуку
class BinaryTreeSearch {
private:
	Node* m_root;

public:
	BinaryTreeSearch() { m_root = nullptr; }

	//функція для створення дерева
	void fillTree(char& value,struct Node*& subtree)
	{
		if (subtree == nullptr)
		{
			subtree = new Node();
			subtree->m_value = std::tolower(value);
			subtree->is_visited = false;
			subtree->m_left = nullptr;
			subtree->m_right = nullptr;
		}
		else if (value < subtree->m_value) fillTree(value, subtree->m_left);
		else fillTree(value, subtree->m_right);
	}

	//функція для додавання елемента до дерева
	void insertData(char& value) { fillTree(value, m_root); }

	//пошук значення в дереві
	bool findData(struct Node* tree, char& value) {
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
	bool isConsonant(char& c) {
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

	//пошук вершини
	struct Node* findNode(struct Node* head, char& value) const
	{
		if (head == nullptr) return nullptr;
		if (head->m_value == value) return head;
		if (value < head->m_value) return findNode(head->m_left, value);
		return findNode(head->m_right, value);
	}

	//пошук батьківської вершини
	Node* findParentNode(char& value) const
	{
		Node* parent = nullptr;
		Node* current = m_root;

		while (current != nullptr && current->m_value != value)
		{
			parent = current;

			if (value < current->m_value)
				current = current->m_left;
			else
				current = current->m_right;
		}

		if (current == nullptr)
			return nullptr;

		return parent;
	}

	//запис піддерева у прямому порядку
	void wirteNodePreorder(Node* node, std::string& result) const
	{
		if (node == nullptr)
			return;

		result += node->m_value;
		result += ' ';

		wirteNodePreorder(node->m_left, result);
		wirteNodePreorder(node->m_right, result);
	}

	//функція для виводу батька і нащадків для вибраної вершини(за значенням value)
	std::string parentAndDescendants(char value) const
	{
		value = std::tolower(value);
		Node* target = findNode(m_root, value);
		Node* parent = findParentNode(value);

		if (target == nullptr) return "head not found";


		std::string result = "Parent: ";

		if (parent != nullptr) result += parent->m_value;
		else result += " root";
		
		result += "\nDescendants: ";

		std::string descendants = "";

		wirteNodePreorder(target->m_left, descendants);
		wirteNodePreorder(target->m_right, descendants);

		if (descendants.empty()) result += "no descendants";
		else result += descendants;

		return result;
	}
};