#include<iostream>
#include<vector>
using namespace std;

vector<vector<int>> mergeIntervals(vector<vector<int>>& intervals)
{
    int n=intervals.size();
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i=1;i<n;i++)
    {
        vector<int> prev=res.back();
        vector<int> curr=intervals[i];
        if(prev[1]>=curr[0])
        {  
            res.pop_back();
            res.push_back({prev[0],max(prev[1],curr[1])});
        }
        else
        {
            res.push_back(curr);
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> intervals={{1,3},{2,6},{8,10},{15,18}};
    mergeIntervals(intervals);
}