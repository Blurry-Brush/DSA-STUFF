#include <bits/stdc++.h>

using namespace std;
class Node {
public:
	Node * next;
	int data;

	Node(int data) {
		next = NULL;
		this->data = data;
	}
};

class queueusingll {
	Node * head;
	Node * tail;
	int size;

public:
	queueusingll() {
		head = NULL;
		tail = NULL;
		size = 0;
	}

	int getsize() {
		return size;
	}

	bool isEmpty() {
		return (size == 0);
	}

	void enqueue(int element) {
		Node * newNode  = new Node(element);
		if (head == NULL) {
			head = newNode;
			tail = newNode;
			return;
			size++;

		}

		tail->next = newNode;
		tail = newNode;
		size++;
		return;
	}
	int front() {
		if (isEmpty()) {
			cout << "queue is empty boi" << endl;
			return 0;
		}

		return head->data;

	}

	int dequeue() {
		if (isEmpty()) {
			cout << "queue is empty boi" << endl;
			return 0;
		}

		Node * temp = head;
		head = head->next;

		int ans = temp->data;
		delete temp;
		size--;
		return ans;
	}
};
int main() {

	queueusingll q;

	q.enqueue(40);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);

	cout << q.getsize() << endl;
	cout << q.front() << endl;
	cout << q.dequeue() << endl;
	cout << q.isEmpty() << endl;
	return 0;
}
