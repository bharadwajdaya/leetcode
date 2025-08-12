#include<iostream>
#include<vector>
using namespace std;
int findTheLongestSubstring(string str)
{
    vector<int> lastVisit(32,-2);
    lastVisit[0]=-1;

    auto bit=[](char c)->int{
        switch(c)
        {
            case 'a': return 0;
            case 'e': return 1;
            case 'i': return 2;
            case 'o': return 3;
            case 'u': return 4;
            default:  return -1;
        }
    };
    int mask=0;
    int ans=0;
    for(int i=0;i<str.size();i++)
    {
        int b=bit(str[i]);
        if(b!=-1)
        {
            mask^=(1<<b);
        }
        if(lastVisit[mask]!=-2)
        {
            ans=max(ans,i-lastVisit[mask]);
        }
        else
        {
            lastVisit[mask]=i;
        }
    }
    return ans;
}
int main()
{
    string str="plwxzaeiwxzaeilp";
    cout<<findTheLongestSubstring(str)<<endl;
    return 0;
}