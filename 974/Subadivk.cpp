#include<iostream>
#include<vector>
using namespace std;

int subarraysDivByK(vector<int>& nums, int k) 
{
    int ans=0;
    vector<int> cnt(k,0);
    cnt[0]=1;
    int sum=0;

    for(int x:nums)
    {
        sum+=x;
        int r=(sum%k+k)%k;
        ans+=cnt[r];
        cnt[r]++;
    }
    return ans;
}
int main()
{
    vector<int> nums={4, 5, 0, -2, -3, 1};
    int k=5;
    cout<<subarraysDivByK(nums,k)<<endl;
    return 0;
}