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

void print(Node * head) {

	Node * temp =  head; //now head will remain intact.

	while (temp != NULL) {
		cout << temp -> data << " " ;
		temp = temp -> next;
	}
	//if we don't wanna print the tail node we can put head-> next !=  null in the loop.
}


Node * takeinput_better() {
	int data;

	cin >> data;
	Node * head = NULL;
	Node * tail = NULL;

	while (data != -1) {
		Node * newNode = new Node(data);
		if (head == NULL and tail == NULL) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = tail->next;
			//or
			//tail = newNode;
		}

		cin >> data;
	}


	return head;

}

Node * takeinput() {
	int data;
	cin >> data;

	Node * head = NULL;

	while (data != -1) {
		Node * newNode = new Node(data);
		if (head == NULL) {
			head = newNode;
		}
		else {
			Node * temp = head;

			while (temp -> next != NULL) {
				temp = temp->next;
			}
			temp -> next = newNode;
		}
		cin >> data;
	}

	return head;
}

int elementCount(Node * head) {
	Node * temp = head;
	int ans = 0;
	while (temp != NULL) {
		ans++;
		temp = temp -> next;
	}
	return ans;
}

Node *  insertNode(Node * head, int data, int i) {
	Node * n = new Node(data);
	Node * temp = head;

	if (i == 0) {
		n->next = head;
		head = n;
		return head;
	}



	int count = 0;
	while (count != i - 1 and temp != NULL) {
		temp = temp->next;
		count++;
	}
	if (temp != NULL) {
		n->next = temp -> next;
		temp -> next = n;
	}

	return head;
}
int main() {

	Node * head = takeinput_better();
	//print(head);

	head = insertNode(head, 100, 2);
	print(head);

	return 0;
}
