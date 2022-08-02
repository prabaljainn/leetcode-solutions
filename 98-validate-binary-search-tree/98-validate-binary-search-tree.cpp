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
    bool v(TreeNode* root, long long l, long long r){
        if(root==NULL)
            return true;
        
        if(root->val <l or root->val > r or root->val==l or root->val==r)
            return false;
        
        return v(root->left, l, root->val) and v(root->right, root->val, r);
    }
    
    bool isValidBST(TreeNode* root) {
        return v(root, -1e18, 1e18);
        
    }
};