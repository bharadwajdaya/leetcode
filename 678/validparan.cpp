#include<iostream>
#include<string>
#include<vector>
using namespace std;
bool checkValidString(string s)
{
    int low=0;
    int high=0;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
        {
            low++;
            high++;
        }
        else if(s[i]==')')
        {
            low--;
            high--;
        }
        else
        {
            low--;
            high++;
        }
        if(high<0)
        {
            return false;
        }
        low=max(low,0);
    }
    return low==0? true:false;
}
int main()
{
    string s="(*)";
    cout<<(checkValidString(s)==true ? "Valid":"InValid");
    return 0;
}