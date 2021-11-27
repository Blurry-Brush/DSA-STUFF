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

int nodesCount(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return 0;
	}

	return 1 + nodesCount(root->left) + nodesCount(root->right);
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1

void inOrder(BinaryTreeNode<int> * root) {
	// l -> node ->right

	if (root == NULL) {
		return;
	}

	inOrder(root->left);
	cout << root->data << " ";
	inOrder(root->right);

}
void preOrder(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";

	preOrder(root->left);
	preOrder(root->right);

}

void postOrder(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return;
	}


	postOrder(root->left);
	postOrder(root->right);

	cout << root->data << " ";
}
//1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1
BinaryTreeNode<int> *  constructINandPRE(int * in, int * pre, int inS, int inE, int preS, int preE) {
	if (inS > inE) {
		return NULL;
	}

	BinaryTreeNode<int> * root = new BinaryTreeNode<int>(pre[preS]);
	//for left

	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == pre[preS]) {
			rootIndex = i;

		}
	}

	int LinS = inS;
	int LinE = rootIndex - 1;
	int LpreS = preS + 1;
	int LpreE = LinE - LinS + LpreS;


	//for right//
	int RinS = rootIndex + 1;
	int RinE = inE;

	int RpreS = LpreE + 1;
	int RpreE = preE;

	//done now recursive calls and connect em
	BinaryTreeNode<int> * leftchild = constructINandPRE(in, pre , LinS, LinE, LpreS, LpreE);
	BinaryTreeNode<int> * rightchild = constructINandPRE(in, pre, RinS, RinE, RpreS, RpreE);

	root->left = leftchild;
	root->right = rightchild;

	return root;

}
BinaryTreeNode<int> * constructPostandIn(int * in, int * post, int inS, int inE, int postS, int postE) {
	if (inS > inE) {
		return NULL;
	}

	BinaryTreeNode<int> *root = new BinaryTreeNode<int> (post[postE]);

	int rootIndex = -1;
	for (int i = inS; i <= inE; i++) {
		if (in[i] == post[postE]) {
			rootIndex = i;

		}
	}

	int LinS = inS;
	int LinE = rootIndex - 1;

	int LpostS = postS;
	int LpostE = LinE - LinS + LpostS;


	//for right
	int RinS = rootIndex + 1;
	int RinE = inE;

	int RpostS = LpostE + 1;
	int RpostE = postE - 1;


	root->left = constructPostandIn(in, post, LinS, LinE, LpostS, LpostE);
	root->right = constructPostandIn(in, post, RinS, RinE, RpostS, RpostE);

	return root;

}
int height(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return 0;
	}
	return 1 + max(height(root->left), height(root->right));
}

pair<int, int> diameterHeight(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		pair<int, int> p;
		p.first = 0;
		p.second = 0;
		return p;
	}

	pair<int, int> leftAns = diameterHeight(root->left);
	pair<int, int> rightAns = diameterHeight(root->right);

	int lh = leftAns.first;
	int ld = leftAns.second;

	int rh = rightAns.first;
	int rd = rightAns.second;

	int height = 1 + max(lh, rh);
	int diameter = max(lh + rh, max(ld, rd));

	pair<int, int> p;
	p.first = height;
	p.second = diameter;
	return p;

}

void printLevels(BinaryTreeNode<int> * root) {

	if (root == NULL) {
		return;
	}
	queue<BinaryTreeNode<int> * > pendingNodes;
	pendingNodes.push(root);
	pendingNodes.push(NULL); //indicator.

	while (pendingNodes.size() != 0) {
		BinaryTreeNode<int> * front = pendingNodes.front();
		pendingNodes.pop();

		if (front == NULL) {
			if (pendingNodes.size() == 0) {
				break; //last element.
			}
			cout << endl;
			pendingNodes.push(NULL);
		}
		else {

			cout << front-> data << " ";
			if (front->left != NULL) {
				pendingNodes.push(front->left);
			}

			if (front->right != NULL) {
				pendingNodes.push(front->right);
			}
		}

	}


}

void zigzag(BinaryTreeNode<int> * root) {
	if (root == NULL) {
		return;
	}

	stack<BinaryTreeNode<int> * > s1;
	stack<BinaryTreeNode<int> * > s2;

	s1.push(root);

	
	while (!s1.empty() && !s2.empty()) {
		while (s1.size() != 0) {
			BinaryTreeNode<int> * top = s1.top();
			s1.pop();

			cout << top->data << " ";
			if (top->left != NULL) {
				s2.push(top->left);
			}
			if (top->right != NULL) {
				s2.push(top->right);
			}
		}

		//switching stack
		cout << endl;

		while (s2.size() != 0) {
			BinaryTreeNode<int> * top = s2.top();
			s2.pop();

			cout << top->data << " ";
			if (top->right != NULL) {
				s1.push(top->right);
			}
			if (top->left != NULL) {
				s1.push(top->left);
			}
		}

		cout << endl;
	}

}

int main() {
	BinaryTreeNode<int> * root = takeInputLevelWise();

	//printLevelWise(root);
	zigzag(root);

	return 0;
}
