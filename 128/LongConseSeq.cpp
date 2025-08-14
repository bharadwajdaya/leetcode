#include<iostream>
#include<vector>
#include<string>
#include<unordered_set>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> _set(nums.begin(),nums.end());
        int maxCount=0;
        for(int i=0;i<nums.size();i++)
        {
            int _num=nums[i];
            if(_set.find(_num-1)==_set.end())
            {
                int curr=_num;
                int count=0;
                while(_set.find(curr)!=_set.end())
                {
                    curr++;
                    count++;
                }
                maxCount = max(maxCount, count);
            }   
        }
        return maxCount;

    }
};