#include<iostream>
#include<vector>
#include<string>
using namespace std;
int characterReplacement(string str,int k)
{
    vector<int> count(26,0);
    int n=str.size();
    int maxLen=0;
    int ans=0;
    int start=0;
    for(int end=0;end<n;end++)
    {
        int _ind=str[end]-'A';
        count[_ind]++;
        maxLen=(maxLen,count[_ind]);
        if((end-start+1)-maxLen>k)
        {
            count[str[start]-'A']--;
            start++;
        }
        ans=max(ans,end-start+1);
    }
    return ans;
}
int main()
{
    string str="abca";
    int k=2;
    cout<<characterReplacement(str,k)<<endl;
    return 0;
}