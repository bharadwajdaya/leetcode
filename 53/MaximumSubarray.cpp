#include<iostream>
#include<vector>
#include<string>
using namespace std;
int findLargestSubarray(vector<int>& nums)
{
    int maxNum=nums[0];
    int currSum=nums[0];
    for(int i=1;i<nums.size();i++)
    {
        currSum=max(nums[i],currSum+nums[i]);
        maxNum=max(maxNum,currSum);
    }
    return maxNum;
}
int main()
{
    vector<int> nums={-2,1,-3,4,-1,2,1,-5,4};
    cout<<findLargestSubarray(nums)<<endl;
    return 0;
}