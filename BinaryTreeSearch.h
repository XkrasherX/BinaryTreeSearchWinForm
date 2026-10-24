#pragma once
#include <iostream>
#include <string>
#include <cctype>

const char LOWER_CASE[] = { 'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 't', 'v', 'w', 'x', 'z', '\0' };
const int SIZE_LOWER_CASE = sizeof(LOWER_CASE) / sizeof(LOWER_CASE[0]);

//структура вершини
struct Node {
	char m_value;
	Node* m_left;
	Node* m_right;
};

//клас для бінарного дерева пошуку
class BinaryTreeSearch {
private:
	Node* m_root;

	//функція для створення дерева
	void fillTree(char value, struct Node*& subtree)
	{
		if (subtree == nullptr)
		{
			subtree = new Node();
			subtree->m_value = value;
			subtree->m_left = nullptr;
			subtree->m_right = nullptr;
		}
		else if (value < subtree->m_value) fillTree(value, subtree->m_left);
		else if (value > subtree->m_value) fillTree(value, subtree->m_right);
	}

	//вставити символ в кінець масиву символів 
	void appendChar(char* buf, int cap, int& len, char c) {
		if (len < cap - 1) {
			buf[len++] = c;
			buf[len] = '\0';
		}
	}

	//вставити масив символів в кінець масиву символів
	void appendStr(char* buf, int cap, int& len, const char* s) {
		for (int i = 0; s[i] != '\0'; i++) appendChar(buf, cap, len, s[i]);
	}

	//запис значень дерева у зворотному порядку
	void postorderWrite(Node* n, char* buf, int cap, int& len) {
		if (!n) return;
		postorderWrite(n->m_left, buf, cap, len);
		postorderWrite(n->m_right, buf, cap, len);
		appendChar(buf, cap, len, n->m_value);
		appendChar(buf, cap, len, ' ');
	}

	//запис вершин у прямому порядку
	void preorderWrite(Node* n, char* buf, int cap, int& len) {
		if (!n) return;
		appendChar(buf, cap, len, n->m_value);
		appendChar(buf, cap, len, ' ');
		preorderWrite(n->m_left, buf, cap, len);
		preorderWrite(n->m_right, buf, cap, len);
	}

	//пошук другої приголосної
	void findSecond(Node* n, int& count, char& res) {
		if (!n || res != '\0') return;
		findSecond(n->m_left, count, res);
		findSecond(n->m_right, count, res);
		if (res == '\0' && isConsonant(n->m_value) && ++count == 2)	res = n->m_value;
	}

public:
	BinaryTreeSearch() { m_root = nullptr; }
		
	//функція для додавання елемента до дерева
	void insertData(char value) { 
		char c = std::tolower(value);
		fillTree(c, m_root); 
	}

	//пошук значення в дереві
	bool findData(char value) {
		return findNode(m_root, value) != nullptr;
	}

	//зворотний обхід дерева
	void postorder(char* buf, int cap) {
		int len = 0;
		buf[0] = '\0';
		postorderWrite(m_root, buf, cap, len);
	}
	
	//функція яка перевіряє чи char приголосний
	bool isConsonant(char c) {
		for (int i = 0; i < SIZE_LOWER_CASE - 1; i++) {
			if (c == LOWER_CASE[i]) return true;
			else continue;
		}
		return false;
	}

	//функція я повертає другий приголосний елемент, якщо такий є
	char secondConsonantLetter() {
		int count = 0;
		char res = '\0';
		findSecond(m_root, count, res);
		return res;
	}

	//пошук вершини
	struct Node* findNode(struct Node* head, char value) const
	{
		if (head == nullptr) return nullptr;
		if (head->m_value == value) return head;
		if (value < head->m_value) return findNode(head->m_left, value);
		return findNode(head->m_right, value);
	}
		
	//пошук батьківської вершини
	Node* findParentNode(char value) const
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

	//функція для виводу батька і нащадків для вибраної вершини(за значенням value)
	void parentAndDescendants(char value, char* buf, int cap) {
		int len = 0;
		buf[0] = '\0';

		value = std::tolower(value);
		Node* target = findNode(m_root, value);
		if (!target) {
			appendStr(buf, cap, len, "head not found");
			return;
		}

		Node* parent = findParentNode(value);
		appendStr(buf, cap, len, "Parent: ");
		if (parent) appendChar(buf, cap, len, parent->m_value);
		else appendStr(buf, cap, len, "root");

		appendStr(buf, cap, len, "\nDescendants: ");
		int before = len;
		preorderWrite(target->m_left, buf, cap, len);
		preorderWrite(target->m_right, buf, cap, len);
		if (len == before) appendStr(buf, cap, len, "no descendants");
	}
};