/**********************************************************

	Following is the Binary Tree Node class structure

	template <typename T>
	class BinaryTreeNode {
    	public : 
    	T data;
    	BinaryTreeNode<T> *left;
    	BinaryTreeNode<T> *right;

    	BinaryTreeNode(T data) {
        	this -> data = data;
        	left = NULL;
        	right = NULL;
    	}
	};

***********************************************************/

/*
	The first value of the pair must be the minimum value in the tree and 
	the second value of the pair must be the maximum value in the tree
*/
pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
    if(root == NULL){
        pair<int,int> p;
        p.first = 2147483647;
      //int max
        p.second = -2;
        return p;
    }
    
    pair<int,int> leftAns = getMinAndMax(root->left);
    pair<int,int> rightAns = getMinAndMax(root->right);
    
    int minimum = min(root->data , min(leftAns.first, rightAns.first));
    int maximum = max(root->data , max(leftAns.second, rightAns.second));
    
    pair<int,int> p;
    p.first = minimum;
    p.second = maximum;
    
    return p;   
}
