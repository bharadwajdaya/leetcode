#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
vector<int> kthSmallestPrimeFraction(vector<int> arr,int k)
{
    int n=arr.size();
    auto cmp=[](auto &a,auto& b){
        return (double)(arr[a.first]/arr[a.second]) > (double)arr[b.first]/arr[b.second];
    };
    priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(cmp)> pq(cmp);
    for(int j=1;j<n;j++)
    {
        pq.push({0,j});
    }

    for(int cnt=0;cnt<k-1;cnt++)
    {
        auto [i,j]=pq.top();
        pq.pop();
        if(i+1 < j)
        {
            pq.push({i+1,j});
        }
    }
    auto [i,j]=pq.top();
    return {arr[i],arr[j]};
}
int main()
{
    vector<int> arr={1,2,3,5};
    int k=3;
    vector<int> res=kthSmallestPrimeFraction(arr,k);
    for(int num:res)
    {
        cout<<num<<","<<endl;
    }
    return 0;
}
