/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include <utility>
class Solution {
public:
        pair<bool, int> helper(TreeNode * root){
                if(root == NULL){
                        pair<int,int> p;
                        p.first = true;
                        p.second = 0;
                        return p;
                }
                
                pair<bool,int> leftans = helper(root->left);
                pair<bool,int> rightans = helper(root->right);
                
                pair<int,int> p;
                p.first = leftans.first and rightans.first and (abs(leftans.second - rightans.second) <= 1);
                
                p.second = 1 + max(leftans.second, rightans.second);
                
                return p;
        }
    bool isBalanced(TreeNode* root) {
        return helper(root).first;
    }
};
