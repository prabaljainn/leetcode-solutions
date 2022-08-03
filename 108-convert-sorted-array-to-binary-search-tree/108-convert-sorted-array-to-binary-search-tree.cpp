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
    TreeNode* help(vector<int> arr, int l, int r){
        if(l>r)
            return NULL;
        int mid = l+ (r-l)/2;
        TreeNode *root = new TreeNode(arr[mid]);
        
        root->right = help(arr, mid+1, r);
        root->left = help(arr, l, mid-1);
        return root;
    }
    
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
       return help(nums, 0, nums.size()-1); 
    }
};