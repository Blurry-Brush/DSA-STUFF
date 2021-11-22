#include <bits/stdc++.h>

using namespace std;

class Node {

public:
	int data;
	Node * next;

	//constructor.
	Node(int data) {
		this->data = data;
		next = NULL;
	}
};
Node * takeinput() {
	int data;
	cin >> data;

	Node * head = NULL;
	Node * tail = NULL;

	while (data != -1) {
		Node * newNode = new Node(data);

		if (head == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
		}

		cin >> data;
	}

	return head;
}

void print(Node * head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}

Node * reverse(Node * head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}
	Node * newhead = reverse(head->next);

	//Node * temp = head;

	head->next->next = head;
	head->next = NULL;

	return newhead;
}
Node * increment(Node * head) {
	head = reverse(head);
	Node * temp = head;
	//Node * prev = NULL;
	while (temp->data == 9) {
		temp->data = 0;
		temp = temp->next;
	}
	//cout << prev->data << endl;
	temp->data++;

	head = reverse(head);

	// if (head->data == 0) {
	// 	Node * n = new Node(1);
	// 	n->next = head;
	// 	head = n;
	// }
	return head;
}

Node * deleteAlternate(Node * head) {
	int i = 0;
	Node* cur = head;
	Node*prev = NULL;
	while (cur) {

		if (i % 2 == 0) {
			//remain
			prev = cur;
			cur = cur->next;
		}
		else {
			//delete
			Node * temp = cur->next;
			prev->next = cur->next;	
			delete cur;
			cur = temp;
		}

		i++;

	}

	return head;
}
int main() {

	Node * head = takeinput();

	head = deleteAlternate(head);
	print(head);

	return 0;
}
