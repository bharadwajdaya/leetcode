#include<iostream>
#include<vector>
#include<string>
using namespace std;
void backtrack(vector<int>& nums,int start,int n,vector<int>& arr,vector<vector<int>>& res)
{
    res.push_back(arr);
    for(int i=start;i<n;i++)
    {
        arr.push_back(nums[i]);
        backtrack(nums,i+1,n,arr,res);
        arr.pop_back();
    }
}
vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> res;
    vector<int> arr;
    backtrack(nums,0,nums.size(),arr,res);
    return res;
}
int main()
{
    vector<int> arr={1,2,3};
    vector<vector<int>> res=subsets(arr);
    for(auto num:res)
    {
        for(int i : num)
        {
            cout<<i;
        }
        cout<<endl;
    }
    return 0;
}