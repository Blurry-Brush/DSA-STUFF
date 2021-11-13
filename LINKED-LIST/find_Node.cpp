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
int main() {

	int t;
	cin >> t;
	while (t--) {
		Node * head = takeinput_better();
		int n;
		cin >> n;
		cout << find(head , n) << endl;

	}
	return 0;
}
