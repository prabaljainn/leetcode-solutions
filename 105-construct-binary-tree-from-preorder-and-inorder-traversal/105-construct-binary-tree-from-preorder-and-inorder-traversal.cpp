/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int n;
    map<int, int> hash;
    vector<int> preorder, inorder;
    TreeNode* recovery(int Lin, int Rin, int Lpre, int Rpre)
    {
        if(Lin > Rin or Lpre>Rpre)
            return NULL;

        int rootVal = preorder[Lpre];

        int br = hash[rootVal];

        TreeNode *root = new TreeNode(rootVal);

        root->left = recovery(Lin, br - 1, Lpre + 1, (Lpre + br - Lin));
        root->right = recovery(br + 1, Rin, (Lpre + br - Lin) + 1, Rpre);

        return root;
    }
    TreeNode* buildTree(vector<int> &Preorder, vector<int> &Inorder)
    {
        preorder = Preorder;
        inorder = Inorder;
        n = preorder.size();
        cout << n << endl;
        for (int i = 0; i < inorder.size(); i++)
        {
            hash[inorder[i]] =i ;
        }
        

        return recovery(0, n - 1, 0, n - 1);
    }
};