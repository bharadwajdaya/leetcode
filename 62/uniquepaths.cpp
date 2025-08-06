#include<iostream>
#include<string>
#include<vector>
#include<numeric>
using namespace std;
int checkPaths(int m,int n,vector<vector<int>>& dp)
{
    if(m==0 && n==0)
    {
        return 1;
    }
    if(m<0 || n<0)
    {
        return 0;
    }
    if(dp[m][n]!=-1)
    {
        return dp[m][n];
    }
    return dp[m][n]=(checkPaths(m-1,n,dp) + checkPaths(m,n-1,dp));
}
int uniquePaths(int m,int n)
{
    vector<vector<int>> dp(m,vector<int>(n,-1));
    return checkPaths(m-1,n-1,dp);
}
int main()
{
    int m=3;
    int n=7;
    cout<<uniquePaths(m,n);
    return 0;
}