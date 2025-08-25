#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<int> findDiagonalOrder(vector<vector<int>>& mat)
{
    if(mat.empty() || mat[0].empty())
    {
        return {};
    }
    int r=0;
    int c=0;
    int m=mat.size();
    int n=mat[0].size();
    vector<int> res;
    bool up=true;
    for(int i=0;i<(m*n);i++)
    {
        res.push_back(mat[r][c]);
        if(up)
        {
            if(r==0)
            {
                c++;
                up=false;
            }
            else if(c==n-1)
            {
                r++;
                up=false;
            }
            else
            {
                r--;
                c++;
            }
        }
        else
        {
            if(r==m-1)
            {
                c++;
                up=true;
            }
            else if(c==0)
            {
                r++;
                up=true;
            }
            else
            {
                r++;
                c--;
            }
        }
    }
    return res;
}
int main()
{
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res=findDiagonalOrder(mat);
    for(int n:res)
    {
        cout<<n<<endl;
    }
    return 0;
}