#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
public:
    void dfs(int start,int kLeft,int sumLeft,vector<int>& path,vector<vector<int>>& ans)
    {
        if(kLeft==0)
        {
            if(sumLeft==0)
            {
                ans.push_back(path);
            }
            return;
        }
        for(int x=start;x<=9;x++)
        {
            if(x>sumLeft)
            {
                break;
            }
            path.push_back(x);
            dfs(x+1,kLeft-1,sumLeft-x,path,ans);
            path.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> path;
        dfs(1,k,n,path,ans);
        return ans;
    }
};

int main()
{
    Solution sol;
    vector<vector<int>> res=sol.combinationSum3(1,1);
    for(auto v:res)
    {
        for(int num:v)
        {
            cout<<num<<",";
        }
        cout<<endl;
    }

}
