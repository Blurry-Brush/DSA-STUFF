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
bool searchBST(BinaryTreeNode<int>*root, int k) {
	if (root == NULL) {
		return false;
	}
	if (root->data == k) {
		return true;
	}
	else if (root->data < k) {
		return searchBST(root->right, k);
	}
	else {
		return searchBST(root->left, k);
	}
}

void printInRange(BinaryTreeNode<int>* root, int k1, int k2) {
	if (root == NULL) {
		return;
	}

	if (root->data > k1)
		printInRange(root->left, k1, k2);
	
	if (root->data >= k1 and root->data <= k2) {
		cout << root->data << " ";
}
	if (root->data < k2)
		printInRange(root->right, k1, k2);

}
int main() {

	BinaryTreeNode<int> * root = takeInputLevelWise();
	int k1, k2;
	cin >> k1 >> k2;

	printInRange(root, k1, k2);
	//if (searchBST(root, k)) cout << "present" << endl; else cout << "absent" << endl;
	//printLevelWise(root);

	return 0;
}
