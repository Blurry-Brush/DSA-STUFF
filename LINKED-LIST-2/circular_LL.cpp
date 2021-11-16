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

int length(Node * head) {

	if (head == NULL) {
		return 0;
	}

	Node * temp = head->next;

	int count = 1;
	while (temp != head) {
		count++;
		temp = temp->next;
	}

	return count;
}
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

	tail->next = head; //connecting the last and the first node.
	return head;
}

void print(Node * head) {
	Node * temp = head;
	Node * tail = head->next;

	while (tail != head) {
		cout << temp->data << " ";
		tail = tail->next;
		temp = temp->next;
	}
	cout << temp->data << " ";


}

Node * insert(Node * head, int element, int i) {
	Node * temp2 = head;
	Node * n = new Node(element);

	if (i == 0) {
		Node * temp = head->next;
		while (temp->next != head) {
			temp = temp->next;
		}

		n->next = head;
		temp->next = n;
		head = n;
		return head;
	}


	int count = 0;
	while (count != i - 1) {
		temp2 = temp2->next;
		count++;
	}

	n->next = temp2->next;
	temp2->next = n;

	return head;

}

Node * deleteNode(Node * head, int i) {
	if (i == 0) {
		Node * temp = head->next;

		while (temp->next != head) {
			temp = temp->next;
		}

		head = head->next;
		temp->next = head;


		return head;
	}

	int count = 0;
	Node * temp2 = head;
	while (count != i - 1) {
		temp2 = temp2->next;
		count++;
	}

	temp2->next = temp2->next->next;

	return head;


}


int main() {

	int t;
	cin >> t;

	while (t--) {
		Node * head = takeinput();
		head = insert(head, 13, 5);
		print(head);

	}

	return 0;
}
