#include<iostream>
#include<vector>
#include<string>
using namespace std;
using vvi = vector<vector<int>>;
using vi = vector<int>;
int eraseOverlapIntervals(vvi intervals)
{
    int count=0;
    sort(intervals.begin(),intervals.end(),[](vector<int>& a,vector<int>& b) {
        return a[1]<b[1];
    } );
    int lastEnd=intervals[0][1];
    for(int i=1;i<intervals.size();i++)
    {
        if(lastEnd>intervals[i][0])
        {
            count++;
        }
        else
        {
            lastEnd=intervals[i][1];
        }
    }
    return count;
}
int main()
{
    vvi intervals={{1,2},{2,3},{3,4},{1,3}};
    // 1,2 2,3 1,3 3,4
    int count=eraseOverlapIntervals(intervals);
    cout<<count<<endl;
    return 0;
}