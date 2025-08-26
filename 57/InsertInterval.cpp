// 57. Insert Interval
// Medium
// Topics
// Companies
// Hint
// You are given an array of non-overlapping 
// intervals intervals where intervals[i] = [starti, endi] 
// represent the start and the end of the ith interval and 
// intervals is sorted in ascending order by starti. 
// You are also given an interval newInterval = [start, end] 
// that represents the start and end of another interval.

// // Insert newInterval into intervals such that intervals 
// is still sorted in ascending order by starti and intervals 
// still does not have any overlapping intervals 
// (merge overlapping intervals if necessary).

// // Return intervals after the insertion.

// // Note that you don't need to modify intervals in-place. 
// You can make a new array and return it.

 

// Example 1:

// Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
// Output: [[1,5],[6,9]]


#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
using vi=vector<int>;
using vvi=vector<vector<int>>;
vvi insertInterval(vvi intervals,vi newInterval)
{
    // [[1,10],[6,9]], newInterval = [2,5]
    // [2,5]
    // 3>2 
    sort(intervals.begin(),intervals.end());
    int i=0;
    int n=intervals.size();
    vvi res;

    while(i<n && intervals[i][1]<newInterval[0])
    {  
        res.push_back(intervals[i]);
        i++;
    }
    while(i<n && intervals[i][0]<=newInterval[1])
    {
        newInterval[0]=min(newInterval[0],intervals[i][0]);
        newInterval[1]=min(newInterval[1],intervals[i][1]);
        i++;
    }
    res.push_back(newInterval);
    while(i<n)
    {
        res.push_back(intervals[i]);
        i++;
    }
    return res;
}
int main()
{
    vvi intervals={{1,3},{6,9}};
    vi newInterval={2,5};
    vvi res=insertInterval(intervals,newInterval);
    return 0;
}