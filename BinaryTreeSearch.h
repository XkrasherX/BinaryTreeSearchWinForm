#pragma once
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

	//функція яка перевіряє чи char приголосний
	bool isConsonant(char c) {
		for (int i = 0; i < SIZE_LOWER_CASE - 1; i++) {
			if (c == LOWER_CASE[i]) return true;
		}
		return false;
	}

	//пошук вершини
	struct Node* findNode(struct Node* head, char value)
	{
		if (head == nullptr) return nullptr;
		if (head->m_value == value) return head;
		if (value < head->m_value) return findNode(head->m_left, value);
		return findNode(head->m_right, value);
	}

	//пошук батьківської вершини
	Node* findParentNode(char value)
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

	void findSecond(Node* n, int& count, char& res) {
		if (!n || res != '\0') return;
		findSecond(n->m_left, count, res);
		findSecond(n->m_right, count, res);
		if (res == '\0' && isConsonant(n->m_value) && ++count == 2)
			res = n->m_value;
	}

	void postorderWrite(Node* n, std::string& result) {
		if (!n) return;
		postorderWrite(n->m_left, result);
		postorderWrite(n->m_right, result);
		result += n->m_value;
		result += ' ';
	}

	//запис піддерева у прямому порядку
	void wirteNodePreorder(Node* node, std::string& result)
	{
		if (node == nullptr)
			return;

		result += node->m_value;
		result += ' ';

		wirteNodePreorder(node->m_left, result);
		wirteNodePreorder(node->m_right, result);
	}

public:
	BinaryTreeSearch() { m_root = nullptr; }

	//функція для додавання елемента до дерева
	void insertData(char value) { 
		value = std::tolower(value);
		fillTree(value, m_root); 
	}

	//пошук значення в дереві
	bool findData(char value) {
		value = std::tolower(value);
		return findNode(m_root, value) != nullptr;
	}

	//зворотній обхід дерева
	std::string postorder()
	{
		std::string result = "";
		postorderWrite(m_root, result);
		return result;
		
	}
	
	//пошук другої приголосної літери
	char secondConsonantLetter() {
		int count = 0;
		char res = '\0';
		findSecond(m_root, count, res);
		return res; 
	}

	//функція для виводу батька і нащадків для вибраної вершини(за значенням value)
	std::string parentAndDescendants(char value)
	{
		value = std::tolower(value);
		Node* target = findNode(m_root, value);
		Node* parent = findParentNode(value);

		if (target == nullptr) return "кореня не знайдено";


		std::string result = "Батько: ";

		if (parent != nullptr) result += parent->m_value;
		else result += " корінь";

		result += " Нащадки: ";

		std::string descendants = "";

		wirteNodePreorder(target->m_left, descendants);
		wirteNodePreorder(target->m_right, descendants);

		if (descendants.empty()) result += "немає нащадків";
		else result += descendants;

		return result;
	}

	//значення кореня ('\0', якщо дерево порожнє)
	char getRootValue() {
		if (m_root == nullptr) return '\0';
		return m_root->m_value;
	}

	//ліве піддерево кореня у зворотному порядку (порожній рядок, якщо його немає)
	std::string leftSubtree() {
		std::string result = "";
		if (m_root != nullptr) postorderWrite(m_root->m_left, result);
		return result;
	}

	//праве піддерево кореня у зворотному порядку
	std::string rightSubtree() {
		std::string result = "";
		if (m_root != nullptr) postorderWrite(m_root->m_right, result);
		return result;
	}
};