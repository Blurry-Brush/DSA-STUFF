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

int length(Node * head) {
	if (head == NULL) {
		return 0;
	}

	return 1 + length(head->next);
}
Node * increment(Node * head) {

	//digit increase 99 999 9999
	int n = length(head);

	Node * temp2 = head;
	int count = 0;

	while (temp2 != NULL) {
		if (temp2->data == 9) {
			count++;
		}

		temp2 = temp2->next;
	}
	//cout << count << endl;
	if (count == n) {
		//all nine
		Node * newNode = new Node(1);
		newNode->next = head;
		head = newNode;

		temp2 = head->next;
		//checkpoint

		while (temp2 != NULL) {
			temp2->data = 0;
			temp2 = temp2->next;
		}

		return head;

	}

	//else
	head = reverse(head);
	Node * temp = head;
	//Node * prev = NULL;
	while (temp->data == 9) {
		temp->data = 0;
		temp = temp->next;
	}
	temp->data++;

	head = reverse(head);


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

	head = increment(head);
	print(head);

	return 0;
}
