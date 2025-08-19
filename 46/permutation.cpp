#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<vector<int>>& res,vector<int>& nums,int ind)
{
    if(ind==nums.size())
    {
        res.push_back(nums);
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        swap(nums[i],nums[ind]);
        backtrack(res,nums,ind+1);
        swap(nums[i],nums[ind]);
    }
}
vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> res;
    backtrack(res,nums,0);
    return res;
}
int main()
{
    vector<int> nums={1,2,3};
    vector<vector<int>> res=permute(nums);
    return 0;
}
/*
1,2,3
1,3,2
2,1,3
2,3,1
3,1,2
3,2,1
*/