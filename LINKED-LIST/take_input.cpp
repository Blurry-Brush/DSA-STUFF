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

Node * takeinput(){
	int data;
	cin >> data;

	Node * head = NULL;

	while(data != -1){
		Node * newNode = new Node(data);
		if(head == NULL){
			head = newNode;
		}
		else{
			Node * temp = head;

			while(temp -> next != NULL){
				temp = temp->next;
			}
			temp -> next = newNode;
		}
		cin >> data;
	}

	return head;
}
int main() {

	Node * head = takeinput();
	print(head);



	//dynamically

	/*Node * n1 = new Node(1);
	Node * n2 = new Node(2);
	Node * n3 = new Node(3);
	Node * n4 = new Node(4);
	Node * n5 = new Node(5);

	Node * head = n1;

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	printdynamically(head);
	*/


	return 0;
}
