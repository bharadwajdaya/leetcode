#include<iostream>
#include<vector>
#include<string>
using namespace std;

bool checkifpossible(vector<int>& nums,int ind,int target)
{
    if(target==0)
    {
        return true;
    }
    if(ind<0 || target<0)
    {
        return false;
    }
    return checkifpossible(nums,ind-1,target-nums[ind]) || checkifpossible(nums,ind-1,target);
}
bool canPartition(vector<int>& nums)
{
    int target=0;
    for(int num:nums)
    {
        target+=num;
    }
    if(target%2!=0)
    {
        return false;
    }
    target=target/2;

    return checkifpossible(nums,nums.size()-1,target);
}
int main()
{
    vector<int> nums={5,5,1,11};
    cout<<canPartition(nums);
    return 0;
}