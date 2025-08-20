#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<int>> min_time(n, vector<int>(n, -1));
        vector<vector<int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        pq.push({grid[0][0], 0, 0});
        min_time[0][0] = grid[0][0];
        
        while (!pq.empty()) {
            vector<int> current = pq.top();
            pq.pop();
            
            int time = current[0];
            int r = current[1];
            int c = current[2];
            
            if (time > min_time[r][c]) {
                continue;
            }
            
            if (r == n - 1 && c == n - 1) {
                return time;
            }
            
            for (const auto& dir : directions) {
                int new_r = r + dir[0];
                int new_c = c + dir[1];
                
                if (new_r >= 0 && new_r < n && new_c >= 0 && new_c < n) {
                    int neighbor_elevation = grid[new_r][new_c];
                    int new_time = max(time, neighbor_elevation);
                    
                    if (new_time < min_time[new_r][new_c] || min_time[new_r][new_c] == -1) {
                        min_time[new_r][new_c] = new_time;
                        pq.push({new_time, new_r, new_c});
                    }
                }
            }
        }
        
        return -1;
    }
};