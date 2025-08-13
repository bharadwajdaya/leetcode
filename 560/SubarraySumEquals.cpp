#include<iostream>
#include<string>
#include<vector>
using namespace std;
int subarraySum(vector<int>& nums,int k)
{
    int sum=0;
    unordered_map<int,int> countMap;
    countMap[0]=1;
    int res=0;
    for(int num:nums)
    {
        sum+=num;
        auto it=countMap.find(sum-k);
        if(it!=countMap.end())
        {
            res+=it->second;
        }
        countMap[sum]++;
    }
    return res;
}
int main()
{
    vector<int> nums={1,1,1};
    int k=2;
    cout<<subarraySum(nums,k)<<endl;
    return 0;
}