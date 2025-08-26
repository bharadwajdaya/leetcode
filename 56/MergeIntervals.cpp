// Given an array of intervals where intervals[i] = [starti, endi], 
// merge all overlapping intervals, and return an 
// array of the non-overlapping intervals 
// that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].




// 1,6 2,5   prev_last>curr_first
// 1,6

// last=st.back();
// last[0]=min(last[0],curr[0])
// last[1]=max(last[1],curr[1])



// prev_last<curr_first  -> to insert it 
// 1,3 4,10
#include<iostream>
#include<vector>
#include<string>
using namespace std;


using vi = vector<int>;
using vvi = vector<vector<int>>;

vvi merge(vvi& intervals)
{
    vvi res;
    res.push_back(intervals[0]);
    for(int i=1;i<intervals.size();i++)
    {
        vi curr=intervals[i];
        vi& prev=res.back();
        if(prev[1]>=curr[0])
        {
            prev[0]=min(prev[0],curr[0]);
            prev[1]=max(prev[1],curr[1]);
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
    vvi intervals={{1,3},{2,6},{8,10},{15,18}};
    vvi ans=merge(intervals);
    for(auto num:ans)
    {
        cout<<num[0] <<" "<<num[1]<< ((num.size()-1==1) ? "":",");
        cout<<endl;
    }
}
