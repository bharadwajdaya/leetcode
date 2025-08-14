#include<queue>
#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;
vector<int> topKFrequent(vector<int> nums,int k)
{
    unordered_map<int,int> _map;
    vector<int> res;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    for(int i=0;i<nums.size();i++)
    {
        _map[nums[i]]++;
    }

    for(auto [num,freq]:_map)
    {
        q.push({freq,num});
        if(q.size()>k)
        {
            q.pop();
        }
    }
    while(!q.empty())
    {
        res.push_back(q.top().second);
        q.pop();
    }
    return res;
}
int main()
{
    vector<int> nums = {1,1,1,2,2,3,4,4,4,4,4};
    int k = 2;
    vector<int> res=topKFrequent(nums,k);
    for(int num:res)
    {
        cout<<num<<",";
    }
    cout<<endl;
}

