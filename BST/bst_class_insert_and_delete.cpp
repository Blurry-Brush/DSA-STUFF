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

class BST {
	BinaryTreeNode<int>*root;
	//constructor(else there will be garbage in the root)
public:
	BST() {
		root = NULL;
	}
	~BST() {
		delete root;
	}
private:
	//helper function
	bool hasData(int data, BinaryTreeNode<int> * node) {
		if (node == NULL) {
			return false;
		}

		if (node->data == data) {
			return true;
		}
		else if (data < node->data) {
			return hasData(data, node->left);
		}
		else {
			return hasData(data, node->right);
		}
	}

	BinaryTreeNode<int> *insert(int data, BinaryTreeNode<int> * node) {
		if (node == NULL) {
			BinaryTreeNode<int> * newNode = new BinaryTreeNode<int>(data);
			return newNode;
		}

		if (data < node->data) {
			//left side
			node->left = insert(data, node->left);
			return node;
		}
		else {
			node->right = insert(data, node->right);
			return node;
		}
	}


	BinaryTreeNode<int> * deleteNode(int data, BinaryTreeNode<int> * node) {
		if (node == NULL) {
			return NULL;
		}
		if (data < root->data) {
			node->left = deleteNode(data, node->left);
			return node;
		}
		else if (data > root->data) {
			node->right = deleteNode(data, node->right);
			return node;
		}
		else {
			//root->data == data
			//again 4 cases
			if (node->left == NULL and node->right == NULL) {
				delete node;
				return NULL;
			}
			else if (node->right == NULL) {
				BinaryTreeNode<int> * temp = node->left;
				node->left = NULL;
				delete node;
				return temp;
			}
			else if (node->left == NULL) {
				BinaryTreeNode<int> * temp = node->right;
				node->right = NULL;
				delete node;
				return temp;
			}
			else {
				//both null
				//will have to find replacement
				//minimum element from the right will be the replacement for the node
				BinaryTreeNode<int> * minNode = node->right;
				while (minNode->left != NULL) {
					minNode = minNode->left;
					//bst property
				}
				int rightmin = minNode->data;
				node->data = rightmin;
				node->right = deleteNode(rightmin , node->right);
				return node;
			}
		}
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

public:
	void print() {
		printLevelWise(root);
	}
	bool hasData(int data) {
		return hasData(data, root);
	}
	void insert(int data) {
		this->root = insert(data, this->root);
	}
	void deleteNode(int data) {
		this->root = deleteNode(data , this->root);
	}
};
int main() {
	BST b;
	b.insert(4);
	b.insert(5);
	b.insert(3);
	b.insert(6);
	b.insert(2);

	b.deleteNode(4);

	b.print();

	return 0;
}
