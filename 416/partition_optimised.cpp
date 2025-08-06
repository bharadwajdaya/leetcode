#include<iostream>
#include<vector>
#include<string>
#include <numeric>
using namespace std;
bool canPartition(vector<int>& nums)
{
    int target=accumulate(nums.begin(),nums.end(),0);
    if(target%2!=0)
    {
        return false;
    }
    target=target/2;
    vector<bool> dp(target+1,false);
    dp[0]=true;

    for(int num:nums)
    {
        for(int j=target;j>=num;j--)
        {
            dp[j]=dp[j]|| dp[j-num];
        }
    }
    return dp[target];
}
int main()
{
    vector<int> nums={5,5,1,11};
    cout<<canPartition(nums);
    return 0;
}