#include<iostream>
#include<string>
#include<vector>
#include <algorithm>
#include<unordered_set>
using namespace std;
bool wordBreak(string s,vector<string> wordDict)
{
    unordered_set<string> _set(wordDict.begin(),wordDict.end());
    int n=s.length();
    vector<bool> dp(n+1,false);
    dp[0]=true;
    for(int i=1;i<s.size();i++)
    {
        for(int j=0;j<s.size();j++)
        {
            string _sub=s.substr(j,i-j);
            if(dp[j] && _set.find(_sub)!=_set.end())
            {
                dp[i]=true;
                break;
            }
        }
    }
    return dp[n];
}
int main()
{
    string s="leetcode";
    vector<string> wordDict={"leet","code"};
    wordBreak(s,wordDict);
}