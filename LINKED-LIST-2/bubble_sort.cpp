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

void print(Node * head) {
	Node * temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


Node * bubble_sort_recursive(Node * head) {
	if (head == NULL or head->next == NULL) {
		return head;
	}

	for (int i = 0; i < length(head); i++) {


		Node * prev = NULL;
		Node * cur = head;


		while (cur->next != NULL) {
			if (cur->data > cur->next->data) {

				Node * n = cur->next;
				if (prev == NULL) {
					cur->next = n->next;
					n->next = cur;

					prev = n;
					//update head
					head = prev;
				}
				else {
					cur->next = n->next;
					prev->next = n;
					n->next = cur;
					prev = n;
				}
			}

			else {
				prev = cur;
				cur = cur->next;
			}



		}
	}

	return head;

}
int main() {


	int t, m, n;
	cin >> t;
	while (t--) {
		Node * head = takeinput_better();
		head = bubble_sort_recursive(head);
		print(head);
	}

	return 0;
}
