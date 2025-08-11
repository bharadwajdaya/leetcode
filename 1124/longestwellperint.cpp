#include<iostream>
using namespace std;

int longestWPI(vector<int>& hours) {
    int n = hours.size();
    vector<int> pre(n + 1, 0);
    for (int i = 1; i <= n; ++i) 
    {
        pre[i] = pre[i - 1] + (hours[i - 1] > 8 ? 1 : -1);
    }
    vector<int> st;
    for (int i = 0; i <= n; ++i) 
    {
        if (st.empty() || pre[i] < pre[st.back()]) 
        {
            st.push_back(i);
        }
    }
    int ans = 0;
    for (int j = n; j >= 0; --j) 
    {
        while (!st.empty() && pre[j] > pre[st.back()]) 
        {
            ans = max(ans, j - st.back());
            st.pop_back();
        }
    }
    return ans;
}
