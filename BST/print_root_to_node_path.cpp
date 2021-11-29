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
int maximum(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return INT_MIN;
	}

	return max(root->data, max(maximum(root->left) , maximum(root->right)));
}
int minimum(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return INT_MAX;
	}

	return min(root->data, min(minimum(root->left) , minimum(root->right)));
}
bool checkBST1(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return true;
	}

	int leftMax = maximum(root->left);
	int rightMin = minimum(root->right);

	bool output = (root->data > leftMax) && (root->data <= rightMin) && checkBST1(root->left) && checkBST1(root->right);

	return output;

}

class isBSTreturn {
public:
	bool isBST;
	int minimum;
	int maximum;
};

isBSTreturn isBST2(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		isBSTreturn output;
		output.isBST = true;
		output.minimum = INT_MAX;
		output.maximum = INT_MIN;
		return output;
	}

	isBSTreturn leftOutput = isBST2(root->left);
	isBSTreturn rightOutput = isBST2(root->right);

	//overall to be returned
	int minimum = min(root->data, min(leftOutput.minimum , rightOutput.minimum));
	int maximum = max(root->data, max(leftOutput.maximum , rightOutput.maximum));
	bool isBSTFinal = (root->data > leftOutput.maximum) && (root->data <= rightOutput.minimum) && leftOutput.isBST && rightOutput.isBST;

	isBSTreturn output;

	output.minimum = minimum;
	output.maximum = maximum;
	output.isBST = isBSTFinal;

	return output;
}

bool isBST3(BinaryTreeNode<int> * root, int min = INT_MIN, int max = INT_MAX) {
	if (root == NULL) {
		return true;
	}

	if (root->data <= min or root->data > max) {
		return false;
	}
	bool isleftOK = isBST3(root->left, min, root->data - 1);
	bool isrightOK = isBST3(root->right, root->data, max);

	return isleftOK and isrightOK;
}

pair<Node *, Node *> flattenBST(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		pair<Node*, Node*> ans;
		ans.first = NULL;
		ans.second = NULL;
		return ans;
	}
	Node * middle = new Node(root->data);

	pair<Node*, Node*> leftOutput = flattenBST(root->left);
	pair<Node*, Node*> rightOutput = flattenBST(root->right);


	Node* lhead = leftOutput.first;
	Node* ltail = leftOutput.second;

	Node* rhead = rightOutput.first;
	Node* rtail = rightOutput.second;

	pair<Node*, Node*> ans;

	if (lhead != NULL and rhead != NULL) {
		ltail->next = middle;
		middle->next = rhead;

		ans.first = lhead;
		ans.second = rtail;
	}
	else if (lhead != NULL and rhead == NULL) {
		ltail->next = middle;

		ans.first = lhead;
		ans.second = middle;
	}
	else if (lhead == NULL and rhead != NULL) {
		middle->next = rhead;
		ans.first = middle;
		ans.second = rtail;
	}
	else {
		//lhead == NULL and rhead == NULL
		ans.first = middle;
		ans.second = middle;
	}

	return ans;

}

vector<int>* pathToNode(BinaryTreeNode<int> * root, int k) {
	//in binary tree.
	//important
	if (root == NULL) {
		return NULL;
	}

	if (root->data == k) {
		vector<int>* ans = new vector<int>();
		ans->push_back(root->data);
		return ans;
		//edge case
	}

	//vector<int> * ans;
	vector<int> * leftOutput = pathToNode(root->left, k);

	if (leftOutput != NULL) {
		//element found and filled
		leftOutput->push_back(root->data);
		return leftOutput;
	}
	//else
	vector<int> * rightOutput = pathToNode(root->right, k);

	if (rightOutput != NULL) {
		rightOutput->push_back(root->data);
		return rightOutput;
	}
	else {
		return NULL;
		//not found
	}
}
void print(Node * head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout << endl;
}
vector<int> * pathToNodeBST(BinaryTreeNode<int> * root, int k){
	//base
	if(root == NULL){
		return NULL;
	}

	if(root->data == k){
		vector<int> output = new vector<int>();
		output->push_back();
	}
	//min max funda maybe
	if(k < root->right->data and root->right != NULL){
		//right eliminate
		vector<int> * leftoutput = pathToNodeBST(root->left, k);
		if(leftoutput != NULL){

		}
	}


}
int main() {

	BinaryTreeNode<int> * root = takeInputLevelWise();


	vector<int> *  v = pathToNode(root, 8);

	for (int i = 0; i < v->size(); i++) {
		cout << v->at(i) << " ";
	}
	//print(flattenBST(root).first);

	return 0;
}
