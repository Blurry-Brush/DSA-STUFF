#include <bits/stdc++.h>

using namespace std;

class Node {

public:
	int data;
	Node * next;
	Node * prev;

	Node(int data) {
		this->data = data;
		next = NULL;
		prev = NULL;
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
			newNode->prev = tail;
			tail = tail->next;
		}

		cin >> data;
	}

	tail->next = head;
	head->prev = tail;

	return head;
}

void print(Node * head) {
	Node * temp = head;
	while (temp->next != head) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << temp->data << " ";
	cout << endl;
}

int length(Node * head) {
	int count = 1;
	Node* temp = head->next;

	while (temp != head) {
		count++;
		temp = temp->next;
	}

	return  count;
}

Node * insert(Node * head, int element, int i) {
	Node * temp = head;
	Node * n = new Node(element);

	if (i == 0) {
		temp->prev->next = n;
		n->prev = head->prev;
		//used head anyway.
		n->next = head;
		head->prev = n;

		head = n;

		return head;
	}

	int count = 0;
	while (count != i - 1) {
		temp = temp->next;
		count++;
	}

	//this takes control of even inserting at last node.
	Node * temp3 = temp->next;
	n->next = temp->next;
	temp->next = n;

	n->prev = temp;
	if (temp3 != NULL) {
		temp3->prev = n;
	}

	return head;
}

Node * deleteNode(Node * head, int i) {
	Node * temp = head;

	if (i == 0) {
		Node * temp2 = temp->next;

		temp->prev->next = temp2;
		temp2->prev = temp->prev;
		head = temp2;
		delete temp;
		return head;
	}


	int count = 0;
	while (count != i) {
		count++;
		temp = temp->next;
	}

	Node * temp2 = temp->next;

	temp->prev->next = temp2;
	if (temp2 != NULL) {
		temp2->prev = temp->prev;
	}
	delete temp;

	return head;
}
int main() {

	int t;
	cin >> t;

	while (t--) {
		Node * head = takeinput();

		head = deleteNode(head, 4);
		//head = insert(head, 10, 5);
		print(head);
		//cout << length(head) << endl;
		//cout << head->prev->data << endl; proof
	}



	return 0;
}
