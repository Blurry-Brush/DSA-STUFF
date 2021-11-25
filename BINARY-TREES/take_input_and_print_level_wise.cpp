#include <bits/stdc++.h>
using namespace std;

template <typename T>
class BinaryTreeNode {
public:
	T data;
	BinaryTreeNode*left;
	BinaryTreeNode*right;
	//constructor
	BinaryTreeNode(T data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
	~BinaryTreeNode() {
		//recursive deletion
		delete left;
		delete right;
	}
};

void print(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return;
		//here it is a base case.
	}
	//stylized print

	cout << root->data << " : ";
	if (root->left != NULL) {
		cout << "L" << root->left->data << " , ";
	}
	if (root->right != NULL) {
		cout << "R" << root->right->data;
	}
	cout << endl;
	print(root->left);
	print(root->right);
}

BinaryTreeNode<int> * takeInput() {
	//-1 as indicator of null

	int rootdata;
	//cout << "Enter data" << endl;
	cin >> rootdata;

	if (rootdata == -1) {
		return NULL;
	}

	BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootdata);

	BinaryTreeNode<int> * leftChild = takeInput();
	BinaryTreeNode<int> * rightChild = takeInput();

	root->left = leftChild;
	root->right = rightChild;

	return root;
}

BinaryTreeNode<int> * takeInputLevelWise() {
	int rootdata;
	//cout << "Enter root data" << endl;
	cin >> rootdata;

	if (rootdata == -1) {
		return NULL;
	}

	BinaryTreeNode<int> * root = new BinaryTreeNode<int>(rootdata);
	queue<BinaryTreeNode<int> * > pendingNodes;
	pendingNodes.push(root);
	//nodes whose children are yet to be taken input.

	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();
		//cout << "Enter left child of " << front->data << endl;

		int leftChildData;
		cin >> leftChildData;

		if (leftChildData != -1) {
			BinaryTreeNode<int> * child = new BinaryTreeNode<int>(leftChildData);
			front->left = child;
			pendingNodes.push(child);
		}


		//cout << "Enter right child of " << front->data << endl;

		int rightChildData;
		cin >> rightChildData;

		if (rightChildData != -1) {
			BinaryTreeNode<int> * child = new BinaryTreeNode<int>(rightChildData);
			front->right = child;
			pendingNodes.push(child);
		}
	}

	return root;
}

void printLevelWise(BinaryTreeNode<int> * root) {
	queue<BinaryTreeNode<int> * > pendingNodes;
	pendingNodes.push(root);



	while (pendingNodes.size() != -1) {
		BinaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();

		cout << front->data << " : ";
		if (front->left != NULL) {
			cout << "L" << front->left->data << " , ";
		}
		if (front->right != NULL) {
			cout << "R" << front->right->data;
		}

		cout << endl;
		pendingNodes.push(front->left);
		pendingNodes.push(front->right);

	}
}
int main() {
	BinaryTreeNode<int> * root = takeInputLevelWise();

	printLevelWise(root);


	return 0;
}
