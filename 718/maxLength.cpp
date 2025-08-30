#include<iostream>
#include<vector>
#include<string>
using namespace std;
int findLength(vector<int> nums1,vector<int> nums2)
{
    int n=nums1.size();
    int m=nums2.size();
    vector<vector<int>> dp(n,vector<int>(m,0));
    int _max=0;
    for(int i=1;i<n;i++)
    {
        for(int j=1;j<m;j++)
        {
            if(nums1[i-1]==nums2[j-1])
            {
                dp[i][j]=dp[i-1][j-1]+1;
                _max=max(dp[i][j],_max);
            }
        }
    }
    return _max;
}
int main()
{
    vector<int> nums1={1,2,3,2,1};
    vector<int> nums2={3,2,1,4,7};
    cout<<findLength(nums1,nums2);
    return 0;
}