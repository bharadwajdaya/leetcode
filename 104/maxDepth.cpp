class Solution {
public:
    int findDepth(TreeNode* root)
    {
        if(!root)
        {
            return 0;
        }
        return max(findDepth(root->left),findDepth(root->right))+1;
    }
    int maxDepth(TreeNode* root) {
        return findDepth(root);
    }
};