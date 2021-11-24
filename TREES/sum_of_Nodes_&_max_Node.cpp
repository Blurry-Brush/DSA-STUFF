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
//input again not base case as it is handled in loop
TreeNode<int> * takeInput() {
	int rootdata;
	//cout << "Enter data" << endl;
	cin >> rootdata;

	TreeNode<int> * root = new TreeNode<int>(rootdata);

	int n;

	//cout << "Enter no of chidren of " << rootdata << endl;
	cin >> n;

	//imagine as subtrees.
	//let recursion handle.

	for (int i = 0; i < n; i++) {
		TreeNode<int> * child = takeInput();
		//returns the subroot node of the subtree
		//connect it to the original root.
		root->children.push_back(child);
	}

	return root;
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

int main() {

	//1 -- (2 3)

	// TreeNode<int> * root = new TreeNode<int>(1);
	// TreeNode<int> * node1 = new TreeNode<int>(2);
	// TreeNode<int> * node2 = new TreeNode<int>(3);

	// root->children.push_back(node1);
	// root->children.push_back(node2);
	TreeNode<int> * root = takeinputLevelWise();
	printLevelWise(root);
	return 0;
}
