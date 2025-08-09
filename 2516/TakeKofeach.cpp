#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

int takeCharacters(string s,int k)
{
    int n=s.length();
    int minMin=n+1;
    int left=0;
    int right=0;
    unordered_map<char,int> _map;
    for(char ch:s)
    {
        _map[ch]++;
    }

    if(_map['a']<k || _map['b']<k|| _map['c']<k)
    {
        return -1;
    }

    while(right<n)
    {
        _map[s[right]]--;
 
        while(_map['a']<k || _map['b']<k || _map['c']<k)
        {
            _map[s[left]]++;
            left++;
        }
        minMin=min(minMin,(n-(right-left+1)));
        right++;
    }
    return minMin==n+1?-1:minMin;
}
int main()
{
    string s="aabaaaacaabc";
    int k=2;
    int min=takeCharacters(s,k);
    cout<<min<<endl;
    return 0;
}