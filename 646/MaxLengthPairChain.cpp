#include<string>
#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),[](auto &a,auto &b){
            return a[1]<b[1];
        });
        int currEnd=INT_MIN;
        int count=0;
        for(auto& p:pairs)
        {
            if(p[0]>currEnd)
            {
                count++;
                currEnd=p[1];
            }
        }
        return count;
    }
};