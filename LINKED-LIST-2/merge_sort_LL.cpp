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

Node * mergetwosortedLL(Node* head1, Node * head2) {
	Node*finalHead = NULL;
	Node*finalTail = NULL;

	while (true) {
		if (head1 == NULL) {
			//dont have to take finaltail to the last node just use to connect
			finalTail->next = head2;
			break;
		}
		else if (head2 == NULL) {
			//dont have to take finaltail to the last node just use to connect

			finalTail->next = head1;
			break;
		}


		if (head1->data < head2->data) {

			if (finalTail == NULL) {
				//for the first node
				finalHead = head1;
				finalTail = head1;
				head1 = head1->next;
			}
			else {
				finalTail->next = head1;
				head1 = head1->next;
				finalTail = finalTail->next; // or finaltail = head1;
			}
		}
		else {
			if (finalTail == NULL) {
				//for the first Node
				finalHead = head2;
				finalTail = head2;
				head2 = head2->next;
			}
			else {
				finalTail->next = head2;
				head2 = head2->next;
				finalTail = finalTail->next;
			}
		}
	}

	return finalHead;
}

Node * middle(Node * head) {
	Node * mid = head;
	Node * tail = head->next;

	//mid wala
	while (mid->next != NULL and (tail->next != NULL or tail != NULL)) {
		mid = mid->next;
		tail = tail->next->next;
	}
	return mid;
}

Node * mergeSort(Node * head) {
	//if size is 0 or 1(already sorted)
	if (head == NULL or head->next == NULL) {
		return head;
	}

	//split and call merge sort on both halves.
	Node* mid = middle(head);
	Node * head2 = mid->next;
	mid->next = NULL;

	Node * newHead = mergetwosortedLL(mergeSort(head), mergeSort(head2));

	return newHead;
}
int main() {


	int t;
	cin >> t;

	while (t--) {
		Node * head = takeinput_better();

		head = mergeSort(head);
		print(head);
	}
	cout << 123 << endl;
	return 0;
}
