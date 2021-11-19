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

void deleteNnodes(Node * head, int m, int n) {
	Node * curr = head;
	Node * t;
	int count;
	while (curr) {

		//skip first m nodes
		for (count = 1; count < m and curr != NULL; count++) {

			curr = curr->next;
		}

		if (curr == NULL) {
			return;
		}

		//delete next n nodes
		t = curr->next;
		for (count = 1 ; count <= n and t != NULL; count++) {

			Node * temp = t;
			t = t->next;

			delete temp;
		}

		curr->next = t;
		curr = t;
	}
}

Node * swap(Node * head, int i, int j) {
	Node * curi = head;
	Node * previ = NULL;
	Node * curj = head;
	Node * prevj = NULL;

	//searching and setting
	//for i;
	if (i >= length(head) or j >= length(head)) {
		return head;
	}

	int count = 0;
	while (count != i ) {
		count++;
		previ = curi;
		curi = curi->next;
	}
	count = 0;

	while (count != j ) {
		count++;
		prevj = curj;
		curj = curj->next;
	}

	if (previ == NULL) {
		//first
		head = curj;
	}
	else {
		previ->next = curj;
	}


	if (prevj == NULL) {
		head = curj;
	}
	else {
		prevj->next = curi;
	}


	Node * temp = curj->next;
	curj->next = curi->next;
	curi->next = temp;

	return head;

}
Node * reverseRecursive(Node * head, Node * end) {
	if (head->next == end) {
		return head;
	}

	Node * reverseHead = reverseRecursive(head->next, end);
	head->next->next = head;
	head->next = NULL;

	return reverseHead;
}

void reverse(Node*s, Node*e) {

	//reverses [s,e]

	Node *p = NULL, *c = s, *n = s->next;

	while (p != e) {
		c->next = p;
		p = c;
		c = n;

		if (n != NULL) n = n->next;
	}

}

Node* reverseKGroup_better_space(Node* head, int k) {
	if (head == NULL or head->next == NULL or k == 1) {
		return head;
	}
	Node * dummy = new Node(-1);
	dummy->next = head;
	Node * beforeStart = dummy, * e = head;

	int i = 0;

	while (e != NULL) {
		i++;
		if (i % k == 0) {
			//reversal.
			Node * s = beforeStart->next;
			Node * temp = e->next;
			reverse(s, e);
			beforeStart->next = e;
			s->next = temp;

			beforeStart = s;
			e = temp; //beforeStart->next;
		}
		else {
			e = e->next;
		}
	}

	return dummy->next; //original head.
}

Node * kreverse(Node * head, int k) {
	//using recursion
	if (head == NULL or  head->next == NULL or k == 1) {
		return head;
	}

	Node * s = head;
	Node  * e = head;
	int inc = k - 1;

	while (inc--) {
		e = e->next;

		if (e == NULL) {
			return head;
		}
	}
	Node * newHead = kreverse(e->next, k);
	reverse(s, e);
	s->next = newHead;

	return e;


}
int main() {


	int t, m, n;
	cin >> t;
	while (t--) {
		Node * head = takeinput_better();
		cin >> m;
		head = kreverse(head, m);
		print(head);
	}

	return 0;
}
