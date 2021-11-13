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


Node * deleteNode(Node * head, int i) {
	int count = 0;
	Node * temp = head;

	if (i == 0) {
		head = temp->next;
		return head;
	}

	while (count != (i - 1) and temp != NULL) {
		temp = temp -> next;
		count++;
	}
	if (temp != NULL) {
		Node * temp2 = temp;
		temp2 = temp2->next;
//temp is pointing to the i-1 element and temp2 is pointing to the ith .
		temp->next = temp2->next;
		delete temp2;
	}
	return head;
}

int lengthrecursive(Node * head) {
	if (head  == NULL) {
		return 0;
	}

	int smallans = lengthrecursive(head->next);
	return 1 + smallans;
}

Node * insertNodeRecursive(Node * head, int data, int i) {
	if (head == NULL) {
		return head;
	}

	Node * newNode = new Node(data);
	Node * smallans;
	if (i == 0) {
		newNode->next = head;
		head = newNode;
	}
	else {
		smallans =  insertNodeRecursive(head->next, data, i - 1);
		head->next = smallans;
	}

	return head;
}

Node * deleteNodeRecursively(Node * head, int i) {
	if (head == NULL) {
		return head;
	}

	Node*smallans;
	if (i == 0) {
		Node * temp = head;
		head = head -> next;
		delete temp;
	}
	else {
		smallans = deleteNodeRecursively(head->next, i - 1);
		head -> next = smallans;
	}
	return head;
}
int main() {

	Node * head = takeinput_better();
	head = deleteNodeRecursively(head, 2);
	print(head);
	return 0;
}
