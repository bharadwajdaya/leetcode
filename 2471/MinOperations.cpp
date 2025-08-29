#include <vector>
#include <string>
#include <iostream>
#include<queue>
using namespace std;
struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
    public:
        int checkForItr(vector<int>& temp)
        {
            vector<pair<int,int>> p;
            int swaps=0;
            int n=temp.size();
            for(int i=0;i<n;i++)
            {
                p.push_back({temp[i],i});
            }
            sort(p.begin(),p.end(),[](pair<int,int> a,pair<int,int> b)
            {
                return a.first<b.first;
            });
            // a = [7, 15, 10, 5]
            // 7,0 15,1 10,2 5,3
            // 5,3 7,0 10,2 15,1
            int i=0;
            vector<char> vis(n,0);
            while(i<n)
            {
                if(vis[i] || p[i].second==i) 
                {
                    i++; 
                    continue;
                }
                int j=i;
                int cycle=0;
                while(!vis[j])
                {
                    vis[j]=1;
                    j=p[j].second;
                    cycle++;
                }
                swaps+=cycle>1 ? cycle-1:0;
                i++;
            }
            return swaps;
        }
        int minimumOperations(TreeNode* root)
        {
            queue<TreeNode*> q;
            q.push(root);
            int res=0;

            while(!q.empty())
            {
                int n=q.size();
                vector<int> temp;
                temp.reserve(n);
                for(int i=0;i<n;i++)
                {
                    TreeNode* top=q.front(); q.pop();
                    temp.push_back(top->val);
                    if(top->left) q.push(top->left);
                    if(top->right) q.push(top->right);
                }    
                res+=checkForItr(temp);
            }
            return res;
        }
        
};
int main()
{
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(4);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(7);
    root->left->right = new TreeNode(6);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(5);
    root->right->left->left = new TreeNode(9);
    root->right->right->right = new TreeNode(10);
    
    Solution sol;
    int result = sol.minimumOperations(root);
    cout << "Minimum operations needed: " << result << endl;
    
}
