#include<iostream>
#include<vector>
#include<string>
#include<queue>
using namespace std;
double maxAverageRatio(vector<vector<int>>& classes,int extraStudents)
{
    auto calculateGain= [](int pass,int total)
    {
        return ((double)(pass+1)/(total+1))- ((double)pass/total);
    };
    priority_queue<pair<double,pair<int,int>>,vector<pair<double,pair<int,int>>>> pq;
    for(auto& c:classes)
    {
        int pass=c[0];
        int total=c[1];
        double gain=calculateGain(pass,total);
        pq.push({gain,{pass,total}});
    }
    for(int i=0;i<extraStudents;i++)
    {
        auto top=pq.top();
        pq.pop();
        int pass=top.second.first;
        int total=top.second.second;
        pass++;
        total++;
        double newGain=calculateGain(pass,total);
        pq.push({newGain,{pass,total}});
    }
    double totalRatio=0.0;
    while(!pq.empty())
    {
        auto top=pq.top();
        pq.pop();
        int pass=top.second.first;
        int total=top.second.second;
        totalRatio+=(double)pass/total;
    }
    return totalRatio/classes.size();
}
int main()
{
    vector<vector<int>> classes={{1,2},{3,4},{2,2}};
    int extraStudents=2;
    cout<<maxAverageRatio(classes,extraStudents);
    return 0;
}