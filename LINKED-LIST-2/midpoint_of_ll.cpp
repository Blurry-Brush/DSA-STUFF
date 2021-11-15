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

Node * takeinput_better() {
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
int length(Node * head) {
	if (head == NULL) {
		return 0;
	}

	return 1 + length(head->next);
}

int midpointLL(Node * head) {
	if (head == NULL) {
		return -1;
	}
	Node * slow = head;
	Node * fast = head->next;

	while (true) {
		if (fast->next == NULL) {
			break;
		}
		else if (fast->next->next == NULL) {
			slow = slow->next;
			fast = fast->next->next;
			break;
		}

		slow = slow->next;
		fast = fast->next->next;
	}

	return slow->data;
}
int main() {


	int t;
	cin >> t;

	while (t--) {
		Node * head = takeinput_better();
		cout << midpointLL(head) << endl;
	}

	return 0;
}
