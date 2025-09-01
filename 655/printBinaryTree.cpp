#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int val): val(val),left(nullptr),right(nullptr) {}
};
class Solution
{
    public:
    int findTheHeight(TreeNode* root)
    {
        if(root==nullptr)
        {
            return 0;
        }
        return 1+max(findTheHeight(root->left),findTheHeight(root->right));
    }
    void fill(TreeNode* root,vector<vector<string>>& res,int r,int c,int h)
    {
        if(!root)
        {
            return;
        }
        res[r][c]=to_string(root->val);
        if(h - r - 1 >= 0) 
        {
            int spread = 1 << (h - r - 1);
            if(root->left)
            {
                fill(root->left, res, r + 1, c - spread, h);
            }
            if(root->right)
            {
                fill(root->right, res, r + 1, c + spread, h);
            }
        }
    }
    vector<vector<string>> printTree(TreeNode* root)
    {
        int h=findTheHeight(root);
        int m=h;
        int n=(1<<(h))-1;
        vector<vector<string>> res(m,vector<string>(n,""));
        fill(root,res,0,(n-1)/2,h-1);
        return res;
    }
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(4);
    Solution sol;
    vector<vector<string>> result = sol.printTree(root);
    for(const auto& row : result)
    {
        cout << "[";
        for(int i = 0; i < row.size(); i++)
        {
            cout << "\"" << row[i] << "\"";
            if(i < row.size() - 1) cout << ",";
        }
        cout << "]" << endl;
    }
    return 0;
}