#include<iostream>
#include<vector>
using namespace std;
const int MOD = 1'000'000'007;
long long modpow(long long pow)
{
    long long val=2;
    long long res=1;
    while(pow>0)
    {
        if(pow&1)
        {
            res=(res*val)%MOD; 
        }
        val=(val*val)%MOD;
        pow>>=1;
    }
    return res;
}
vector<int> productQueries(int n, vector<vector<int>>& queries) 
{
    vector<int> pows;
    
    for(int i=0;i<32;i++)
    {
        if(n& (1<<i))
        {
            pows.push_back(i);
        }
    }
    int pow_size=pows.size();
    vector<long long> prefixSum(pow_size+1,0);
    for(int i=0;i<pow_size;i++)
    {
        prefixSum[i+1]=prefixSum[i]+pows[i];
    }
    vector<int> ans;
    ans.reserve(queries.size());
    for(auto& q:queries)
    {
        int l=q[0];
        int r=q[1];
        long long expSum=prefixSum[r+1]-prefixSum[l];
        ans.push_back((int)modpow(expSum));
    }

    return ans;
}
int main()
{
    vector<vector<int>> queries={{0,1},{2,2},{0,3}};
    int n=15;
    vector<int> res=productQueries(n,queries);
    for(int num:res)
    {
        cout<<num<<endl;
    }
}