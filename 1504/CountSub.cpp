// Count Submatrices With All Ones
#include<vector>
using namespace std;
class Solution {
public:
    long long numSubmat(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> h(n, 0);
        long long ans = 0;

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                h[j] = mat[i][j] ? h[j] + 1 : 0;
            }
            vector<pair<int,int>> st;
            long long row_sum = 0;

            for (int j = 0; j < n; ++j) {
                int height = h[j];
                int cnt = 1;
                while (!st.empty() && st.back().first >= height) {
                    auto [ph, pc] = st.back(); st.pop_back();
                    row_sum -= 1LL * (ph - height) * pc; 
                    cnt += pc;
                }

                st.emplace_back(height, cnt);
                row_sum += height;   
                ans += row_sum;     
            }
        }
        return ans;
    }
};
