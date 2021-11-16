#include <bits/stdc++.h>

using namespace std;

class Node {

public:
	int data;
	Node * next;
	Node * prev;
	//constructor.
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
			Node * prev2 = tail;
			tail = tail->next;
			tail->prev = prev2;
		}

		cin >> data;

	}

	return head;
}

void print(Node * head) {
	//normal
	Node * temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int length(Node * head) {
	//normal
	int count = 0;
	Node * temp = head; \

	while (temp != NULL) {
		temp = temp->next;
		count++;
	}

	return count;
}
Node * insert(Node * head, int element, int i) {
	Node * temp = head;
	Node * n = new Node(element);

	if (i == 0) {
		//first element
		n->next = temp;
		temp->prev = n;
		head = n;
		return head;
	}


	int count = 0;

	while (count != i - 1) {
		temp = temp->next;
		count++;
	}
	Node * temp2 = temp->next;

	if (temp2 != NULL) {
		temp->next = n;
		n->prev = temp;

		n->next = temp2;
		temp2->prev = n;
	}
	else {

		//last element
		temp->next = n;
		n->prev = temp;

	}

	return head;
}

Node * deleteNode(Node * head, int i) {
	Node * temp = head;

	if (i == 0) {
		head = temp->next;
		temp->next->prev = NULL;
		delete temp;
		return head;
	}

	int count = 0;
	while (count != i ) {
		temp = temp->next;
		count++;
	}

	// if(temp->next == NULL){
	// 	//last node
	// 	temp->prev = NULL;
	// }
	// else{

	// }
	temp->prev->next = temp->next;
	temp->prev = NULL;

	if (temp->next != NULL) {
		temp->next->prev = temp->prev;

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
		print(head);

	}


	return 0;
}
