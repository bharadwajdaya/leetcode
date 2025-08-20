#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int r=matrix.size();
        if(r==0)
        {
            return 0;
        }
        int c=matrix[0].size();
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(i>0 && j>0 && matrix[i][j]==1)
                {
                    matrix[i][j]=1+min({matrix[i-1][j],matrix[i-1][j-1],matrix[i][j-1]});
                }
                count+=matrix[i][j];
            }
        }
        return count;
    }
};