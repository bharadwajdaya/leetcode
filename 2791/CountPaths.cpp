#include<iostream>
#include<vector>
#include<queue>
using namespace std;
class Solution {
public:
    long long countPalindromePaths(vector<int>& parent, string s) 
    {
        int n=parent.size();
        vector<vector<int>> tree(n);
        for(int i=1; i<n; i++){
            tree[parent[i]].push_back(i);
        }
        queue<pair<int, int>> q;
        q.push({0,0});
        unordered_map<int, int> freq;
        long long ans=0;
        while(q.size()){
            auto [node, mask] = q.front();
            q.pop();
            ans+=freq[mask];
            for(int bit=0; bit<26; bit++){
                ans+=freq[mask^(1<<bit)];
            }
            freq[mask]++;
            for(auto &child: tree[node]){
                q.push({child, mask^(1<<(int)(s[child]-'a'))});
            }
        }
        return ans;
    }
};