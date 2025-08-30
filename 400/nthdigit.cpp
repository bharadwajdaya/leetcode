#include<iostream>
#include<string>
#include<vector>
using namespace std;
int findNthDigit(int n)
{
    long long len=1;
    long long count=9;
    long long start=1;
    while(n > count*len)
    {
        n=n-(count*len);
        len++;
        count*=10;
        start*=10;
    }
    long long num=start+(n-1)/len;
    string s=to_string(num);
    return s[(n-1)%len]-'0';
}
int main()
{
    int n=13;
    cout<<findNthDigit(n);
    return 0;
}