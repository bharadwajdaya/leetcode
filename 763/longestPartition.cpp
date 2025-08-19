#include<iostream>
#include<vector>
#include<unordered_map>
#include<string>
using namespace std;
vector<int> partitionLabels(string s)
{
    unordered_map<char,int> _map;
    vector<int> res;
    for(int i=0;i<s.length();i++)
    {
        _map[s[i]]=i;
    }
    // for(auto it:_map)
    // {
    //     cout<<it.first<<" "<<it.second<<endl;
    // }
    int start=0;
    int end=0;
    for(int i=0;i<s.length();i++)
    {
        end=max(end,_map[s[i]]);
        if(end==i)
        {
            res.push_back(end-start+1);
            start=i+1;
        }
    }
    return res;
}
int main()
{
    string s= "ababcbacadefegdehijhklij";
    vector<int> partitions=partitionLabels(s);
    for(int num:partitions)
    {
        cout<<num<<" ";
    }
    cout<<endl;
    return 0;
}