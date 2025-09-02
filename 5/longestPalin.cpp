#include<iostream>
#include<vector>
#include<string>
using namespace std;
int isPalin(int i,int j,string str)
{
    int n=str.length();
    while(i>=0 && j<n && str[i]==str[j])
    {
        i--;
        j++;
    }
    return j-i-1;
}
string findLongestPalin(string str)
{
    int n=str.length();
    if(n==0)
    {
        return "";
    }
    int start=0;
    int maxLen=1;
    for(int i=0;i<n-1;i++)
    {
        int odd=isPalin(i,i,str);
        cout<<odd<<endl;
        int even=isPalin(i,i+1,str);
        cout<<even<<endl;
        int len=max(odd,even);
        if(len>maxLen)
        {
            maxLen=len;
            start=i-(len-1)/2;
        }
    }
    return str.substr(start,maxLen);
}
int main()
{
    string str="babad";
    cout<<findLongestPalin(str)<<endl;
    return 0;
}