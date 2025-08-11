#include<iostream>
#include<vector>
#include<string>
using namespace std;
bool checkSubarraySum(vector<int> nums,int k)
{
    int n=nums.size();
    unordered_map<int,int> indices;
    long long sum=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i];
        int rem=sum%k;
        auto it=indices.find(rem);
        if(it!=indices.end())
        {
            if(i-indices[rem] >= 2)
            {
                return true;
            }
        }
        else
        {
            indices[rem]=i;
        }
    }
    return false;
    
}
int main()
{
    vector<int> nums={2,4,3};
    int k=6;
    cout<<checkSubarraySum(nums,k)<<endl;
    return 0;
}