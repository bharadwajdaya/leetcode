#include<iostream>
#include<vector>
using namespace std;
void backtrack(vector<int>& nums,int currSum,int target,vector<int>& currArr,vector<vector<int>>& res,int ind)
{
    if(currSum==target)
    {
        res.push_back(currArr);
        return;
    }
    if(currSum>target)
    {
        return;
    }
    for(int i=ind;i<nums.size();i++)
    {
        if(i>ind && nums[i]==nums[i-1])
        {
            continue;
        }
        int _ele=nums[i];
        currArr.push_back(_ele);
        currSum+=_ele;
        backtrack(nums,currSum,target,currArr,res,i+1);
        currSum-=_ele;
        currArr.pop_back();
    }
}
vector<vector<int>> findCandidates(vector<int> nums,int target)
{
    vector<vector<int>> res;
    vector<int> curr;
    int currSum=0;
    int ind=0;
    sort(nums.begin(),nums.end());
    backtrack(nums,currSum,target,curr,res,ind);
    return res;
}
int main()
{
    vector<int> nums={10,1,2,7,6,1,5};
    int target=8;
    vector<vector<int>> res=findCandidates(nums,target);
    for(auto& x:res)
    {
        for(int num:x)
        {
            cout<<num;
        }
        cout<<endl;
    }
}