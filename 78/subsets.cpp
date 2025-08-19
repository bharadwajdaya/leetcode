#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>& nums,vector<vector<int>>& res,vector<int>& curr,int ind)
{
    res.push_back(curr);
    for(int i=ind;i<nums.size();i++)
    {
        curr.push_back(nums[i]);
        backtrack(nums,res,curr,i+1);
        curr.pop_back();
    }
}
vector<vector<int>> findSubsets(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> curr={};
    backtrack(nums,res,curr,0);
    return res;
}
int main()
{
    vector<int> nums={1,2,3};
    vector<vector<int>> res=findSubsets(nums);
    return 0;
}

