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
class Solution {
public:
        
        TreeNode* help(vector<int> &arr, int si, int ei){
                if(si > ei){
                        TreeNode * ans = NULL;
                     return ans;
                }
                
                int mid = (si + ei)/2;
                TreeNode * root = new TreeNode (arr[mid]);
                
                TreeNode * leftsubtree = help(arr, si, mid - 1);
                TreeNode * rightsubtree = help(arr, mid+1, ei);
                
                root->left = leftsubtree;
                root->right = rightsubtree;
                
                return root;
                        
                
        }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums , 0, nums.size() - 1);
    }
};
