#include<iostream>
#include<vector>
using namespace std;
int findMaxLength(vector<int>& nums)
{
    unordered_map<int,int> _map;
    _map[0]=-1;
    int sum=0;
    int n=nums.size();
    int maxWidth=0;
    for(int i=0;i<n;i++)
    {
        sum+=nums[i]==1?1:-1;
        cout<<"i "<<i<<" "<<sum<<endl;
        auto it =_map.find(sum);
        if(it!=_map.end())
        {
            int temp=it->second;
            maxWidth=max(maxWidth,i-temp);
        }
        else
        {
            _map[sum]=i;
        }
    }
    return maxWidth;
}
int main()
{
    vector<int> nums={0,1,1,1,1,1,0,0,0};
    cout<<findMaxLength(nums)<<endl;
    return 0;
}