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

int countNodesgreaterthanX(TreeNode<int> * root, int x) {
	if (root == NULL) {
		return false;
		//edge case.
	}
	int ans = 0;

	if (root->data > x) {
		ans++;
	}

	for (int i = 0; i < root->children.size(); i++) {
		ans += countNodesgreaterthanX(root->children[i], x);
	}

	return ans;


}

pair<TreeNode <int> *, int>  nodeWithMaxChildSum(TreeNode<int> * root) {

	pair<TreeNode <int> *, int> ans;

	ans.first = root;
	ans.second = root->data;

	for (int i = 0; i < root->children.size(); i++) {
		ans.second += root->children[i]->data;
	}

	for (int i = 0; i < root->children.size(); i++) {

		pair<TreeNode <int> *, int> subans = nodeWithMaxChildSum(root->children[i]);

		if (subans.second > ans.second) {
			ans = subans;
		}

	}

	return ans;
}

bool identical(TreeNode<int> * root1, TreeNode<int> * root2) {
	//check root and then to recursion

	if (root1->data != root2->data) {
		return false;
	}

	if (root1->children.size() != root2->children.size()) {
		return false;
	}

	for (int i = 0; i < root1->children.size(); i++) {
		bool smallans = identical(root1->children[i], root2->children[i]);
		if (!smallans) {
			return false;
		}
	}



	return true;
}



int nextLargerNode(TreeNode<int> * root, int x) {
	int ans = root->data;
	//check on root later.

	for (int i = 0; i < root->children.size(); i++) {
		int smallans = nextLargerNode(root->children[i], x);

		if (smallans > x) {
			if (ans < x) {
				//root unchecks the first condition
				// ded root.
				ans = smallans;
			}
			else {
				//root is in the game
				if (smallans < ans) {
					ans = smallans;
				}
			}
		}
	}
	if (ans < x) {
		return -1;
		//no ans
	}
	return ans;
}
int main() {

	int x;
	cin >> x;
	TreeNode<int> * root = takeinputLevelWise();

	cout << nextLargerNode(root, x) << endl;
	// if (identical(root1, root2)) {
	// 	cout << "IDENTICAL" << endl;
	// }
	// else {
	// 	cout << "NON-IDENTICAL" << endl;
	// }
	//cout << (nodeWithMaxChildSum(root).first)->data << " " << nodeWithMaxChildSum(root).second << endl;
	return 0;
}
