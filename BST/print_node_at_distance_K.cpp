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

BinaryTreeNode<int> * LCA_BST(BinaryTreeNode<int> * root, BinaryTreeNode<int> * n1, BinaryTreeNode<int>* n2) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == n1->data) {
		return root;
	}

	if (root->data == n2->data) {
		return root;
	}

	if (n1->data < root->data and n2->data < root->data) {
		return LCA_BST(root->left, n1, n2);
	}
	else if (n1->data > root->data and n2->data > root->data) {
		return LCA_BST(root->right, n1, n2);
	}
	else {
		//opposite tree
		return root;
	}


}

int height(BinaryTreeNode<int> * root) {
	if (root == NULL) return 0;
	return 1 + max(height(root->left), height(root->right));
}

vector<int> maxBST(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		vector<int> ans;
		//ans.push_back(0);
		return ans;
	}
	vector<int> leftans = maxBST(root->left);
	vector<int> rightans = maxBST(root->right);

	vector<int> ans;
	if (isBST3(root)) {
		ans.push_back(height(root));
	}
	for (int i = 0; i < leftans.size(); i++) {
		ans.push_back(leftans[i]);
	}
	for (int i = 0; i < rightans.size(); i++) {
		ans.push_back(rightans[i]);
	}
	sort(ans.begin(), ans.end() , greater<int>());
	return ans;
}

//better time complexity
class maxreturn {
public:
	int min;
	int max;
	bool isbst;
	int heightbst;

};

maxreturn maxheightbst(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		maxreturn output;
		output.min = INT_MAX;
		output.max = INT_MIN;
		output.isbst = true;
		output.heightbst = 0;
		return output;
	}

	maxreturn leftans = maxheightbst(root->left);
	maxreturn rightans = maxheightbst(root->right);
	//min, max, isbst,height

	//check if whole tree is bst or not
	if (leftans.isbst and rightans.isbst and leftans.max < root->data and rightans.min >= root->data) {
		//whole tree is bst
		maxreturn output;
		output.min = min(root->data, min(leftans.min , rightans.min));
		output.max = max(root->data, max(leftans.max , rightans.max));
		output.isbst = true;
		output.heightbst =  1 + max(leftans.heightbst, rightans.heightbst);
		return output;
	}
	else {
		maxreturn output;
		output.min = min(root->data, min(leftans.min , rightans.min));
		output.max = max(root->data, max(leftans.max , rightans.max));
		output.isbst = false;
		output.heightbst = max(leftans.heightbst, rightans.heightbst);
		return output;
	}
}

int replace(BinaryTreeNode<int> * root, int sum) {
	if (root == NULL) {
		return 0;
	}

	int rightans = replace(root->right, sum);
	root->data += rightans;
	int leftans = replace(root->left, sum);
	root->left->data += root->data;

	return rightans + leftans;
}
void pathsumroottoleaf(BinaryTreeNode<int> * root, int k , vector<int>path) {
	if (root == NULL) {
		return;
	}

	path.push_back(root->data);
	k -= root->data;
	if (!root->left and !root->right) {
		//leaf
		if (k == 0) {
			for (auto x : path) {
				cout << x << " ";
			}
			cout << endl;
		}

		path.pop_back();
		return;
	}


	pathsumroottoleaf(root->left, k, path);
	pathsumroottoleaf(root->right, k, path);


}

void printAtdistanceK(BinaryTreeNode<int> * root, int k) {
	if (root == NULL) {
		return;
	}
	if (k == 0) {
		cout << root->data << " ";
	}

	printAtdistanceK(root->left, k - 1);
	printAtdistanceK(root->right, k - 1);

}
int printNodeatK(BinaryTreeNode<int> * root, int target, int k) {
	if (root == NULL) {
		return -1;
	}


	if (root->data == target) {
		printAtdistanceK(root, k );
		return 0;
	}

	int ld = printNodeatK(root->left, target, k);

	if (ld != -1) {

		if (ld + 1 == k) {
			cout << root->data << endl;
		}
		else {
			printAtdistanceK(root->right, (k - ld - 2));
			//return k - ld - 2;
		}
		return ld + 1;
	}

	else {

		int rd = printNodeatK(root->right, target, k);

		if (rd != -1) {
			if (rd + 1 == k) {
				cout << root->data << endl;
			}
			else {
				printAtdistanceK(root->left, (k - rd - 2));
				//return (k - rd - 2);
			}
			return rd + 1;
		}
	}

	return -1;

}
int main() {

	BinaryTreeNode<int> * root = takeInputLevelWise();

	int ans = printNodeatK(root , 3, 1);
	//cout << ans << endl;
	//printAtdepthK(root, 1);
	//cout << maxheightbst(root).heightbst << endl;

	return 0;
}
