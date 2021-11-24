#include <bits/stdc++.h>
using namespace std;

template <typename T>

class TreeNode {

public:
	T data;
	vector<TreeNode<T> *> children;

	TreeNode(T data) {
		this->data = data;
	}

	~TreeNode() {
		for (int i = 0 ; i < children.size(); i++) {
			delete children[i];
		}
	}
};





void print(TreeNode<int> * root) {

	if (root == NULL) {
		return;
		//not a base case but a edge case.
	}
	//base case is already taken care of when the there is only one single node.

	cout << root->data << ": ";

	for (int i = 0; i < root->children.size(); i++) {
		cout << root->children[i]->data << ",";
	}
	cout << endl;

	for (int i = 0; i < root->children.size(); i++) {
		print(root->children[i]);
	}
}
void printLevelWise(TreeNode<int> * root) {
	if (root == NULL) {
		return;
		//edge case not the base case.
	}

	queue<TreeNode<int> * > q;
	q.push(root);

	while (q.size() != 0) {
		TreeNode<int> * front = q.front();
		q.pop();

		cout << front->data << " : ";

		for (int i = 0; i < front->children.size(); i++) {
			cout << front->children[i]->data << ",";
			q.push(front->children[i]);
		}
		cout << endl;
	}
}


TreeNode<int> * takeinputLevelWise() {
	int rootdata;
	//cout << "Enter the root data " << endl;
	cin >> rootdata;
	TreeNode<int> * root = new TreeNode<int> (rootdata);

	queue<TreeNode<int> *> pendingNodes;
	pendingNodes.push(root);

	while (pendingNodes.size() != 0) {
		int n;
		TreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();

		//cout << "Enter the num of chidren of " << front->data << endl;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int childData;

			//cout << "Enter the " << i << "th child of " << front->data << endl;
			cin >> childData;
			TreeNode<int> * child = new TreeNode<int>(childData);

			front->children.push_back(child);
			pendingNodes.push(child);

		}
	}
	return root;
}

void preOrder(TreeNode<int> * root) {
	//first root , then child
	//like the first one we did.
	//recursion logic
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";

	for (int i = 0; i < root->children.size(); i++) {
		preOrder(root->children[i]);
	}
}

void postOrder(TreeNode<int> * root) {
	if (root == NULL) {
		return;
	}

	for (int i = 0; i < root->children.size(); i++) {
		postOrder(root->children[i]);
	}

	cout << root->data << " ";


}

bool searchX(TreeNode<int> * root, int x) {
	if (root == NULL) {
		return false;
		//edge case.
	}

	if (root->data == x) {
		return true;
	}
	for (int i = 0; i < root->children.size(); i++) {
		return searchX(root->children[i], x);
	}


	return false;
}

int main() {


	TreeNode<int> * root = takeinputLevelWise();
	int x;
	cin >> x;

	cout << searchX(root, x);
	return 0;
}
