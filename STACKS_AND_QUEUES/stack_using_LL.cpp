#include <bits/stdc++.h>

using namespace std;

template <typename T>

class Node {
public:
	T data;
	Node <T> * next;

	Node(T data) {
		this->data = data;
		next = NULL;
	}
};
template <typename T>

class stackusingLL {
	Node<T> * head;
	int size;

public:
	stackusingLL() {
		head = NULL;
		size = 0;
	}

	void push(T element) {
		Node<T> * newNode = new Node<T>(element);

		if (head == NULL) {
			head = newNode;
			size++;
			return;
		}

		newNode->next = head;
		head = newNode;
		size++;
		return;
	}

	int getsize() {
		return size;
	}

	T pop() {
		if (head == NULL) {
			cout << "stack is empty boi" << endl;
			return 0;
		}

		T temp = head->data;
		Node <T> *temp2 = head;
		head = head->next;
		delete temp2;
		size--;

		return temp;
	}

	T top() {
		if (head == NULL) {
			cout << "stack is empty boi" << endl;
			return 0;
		}
		return head->data;
	}
	bool isEmpty() {
		return (size == 0);
	}
};

int main() {

	stackusingLL<int>s;

	s.push(10);
	s.push(20);
	s.push(30);

	cout << s.getsize() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;
	cout << s.pop() << endl;

	return 0;
}
