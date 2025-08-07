#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<vector<int>>& res,vector<int>& arr,int ind,int currsum,int n,int target,vector<int>& nums)
{
    if(currsum==target)
    {
        res.push_back(arr);
        return;
    }
    if(currsum>target)
    {
        return;
    }
    for(int i=ind;i<n;i++)
    {
        arr.push_back(nums[i]);
        backtrack(res,arr,i,currsum+nums[i],n,target,nums);
        arr.pop_back();
    }
}
vector<vector<int>> combinationsum(vector<int> nums,int target)
{
    vector<int> arr;
    vector<vector<int>> res;
    backtrack(res,arr,0,0,nums.size(),target,nums);
    return res;
}
int main()
{
    vector<int> nums={2,3,6,7};
    int target=7;
    vector<vector<int>> res=combinationsum(nums,target);

    for(auto& r:res)
    {
        for(int i:r)
        {
            cout<<i<<",";
        }
        cout<<endl;
    }
    return 0;
}