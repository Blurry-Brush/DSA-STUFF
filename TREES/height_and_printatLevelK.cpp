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

int numNodes(TreeNode<int> * root) {
	if (root == NULL) {
		return 0;
	}
	int ans = 1;
	//for the root node

	//base case not required.
	for (int i = 0; i < root->children.size(); i++) {
		ans += numNodes(root->children[i]);
	}

	return ans;
}

int sumNodes(TreeNode<int> * root) {
	int ans = root->data;


	for (int i = 0; i < root->children.size(); i++) {
		ans += sumNodes(root->children[i]);
	}

	return ans;
}

int maxNode(TreeNode<int> * root) {

	int ans = root->data;

	for (int i = 0; i < root->children.size(); i++) {
		int smallans = maxNode(root->children[i]);
		ans = max(ans, smallans);
	}

	return ans;
}

int height(TreeNode<int> * root) {
	if (root == NULL) {
		return 0;
	}
	int ans = 1;
	int subans = 0;
	for (int i = 0; i < root->children.size(); i++) {
		subans = max(subans, height(root->children[i]));

	}


	return ans + subans;
}

void printatLevelK(TreeNode<int> * root, int k) {
	if (root == NULL) {
		return;
	}

	if (k == 0) {
		cout << root->data << endl;
		return;
	}

	for (int i = 0; i < root->children.size(); i++) {
		printatLevelK(root->children[i], k - 1);
	}
}
int main() {


	TreeNode<int> * root = takeinputLevelWise();
	//printLevelWise(root);

	//cout << height(root) << endl;
	printatLevelK(root, 2);
	return 0;
}
