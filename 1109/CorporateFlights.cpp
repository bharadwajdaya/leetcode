#include<iostream>
#include<string>
using namespace std;
vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n)
{
    vector<int> res(n,0);
    for(auto book:bookings)
    {
        int start=book[0];
        int end=book[1];
        int num=book[2];

        res[start-1]+=num;
        if(end<n)
        {
            res[end]-=num;
        }
    }
    for(int i=1;i<n;i++)
    {
        res[i]+=res[i-1];
    }
    return res;
}
int main()
{
    vector<vector<int>> booking={{1,2,10},{2,3,20},{2,5,25}};
    int n=5;
    vector<int> res=corpFlightBookings(booking,n);
    for(int num:res)
    {
        cout<<num<<",";
    }
    cout<<endl;
    return 0;
}