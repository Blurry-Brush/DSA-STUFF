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


int find(Node * head, int element) {

	int count = 0;
	Node * temp = head;
	while (temp->data != element) {
		count++;
		temp = temp->next;
		if (temp == NULL) {
			return -1; //hehe gotcha boi //temp->next will be problematic.
		}
	}
	return count;
}

Node *  appendnodes(int n, Node * head) {
	Node * curr = head;
	Node * prev = NULL;


	if (n == 0 or n  > lengthrecursive(head)) {
		return head;
	}


	int x = lengthrecursive(head) - n;
	int count = 0;
	while (count != x) {
		prev = curr;
		curr = curr -> next;
		count++;


	}

	prev->next = NULL;
	Node * temphead = head;
	head = curr;

	while (curr ->next != NULL) {
		curr = curr->next;
	}

	curr->next = temphead;



	//cout << temp->data << " " << temp2->data << " " << temp3->data << endl;
	return head;



}
int main() {

	int t;
	cin >> t;
	while (t--) {
		Node * head = takeinput_better();
		int n;
		cin >> n;

		head = appendnodes(n, head);
		print(head);
		cout << endl;

	}
	return 0;
}
