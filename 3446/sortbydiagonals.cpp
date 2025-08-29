#include<iostream>
#include<vector>
#include<string>
using namespace std;
void sortDiag(vector<vector<int>>& grid,int r,int c,bool desc)
{
    int n=grid.size();
    vector<int> vals;

    int i=r;
    int j=c;
    vector<int> vals;
    while(i<n && j<n)
    {
        vals.push_back(grid[i][j]);
        i++;
        j++;
    }
    if(desc)
    {
        sort(vals.begin(),vals.end(),greater<int>());
    }
    else
    {
        sort(vals.begin(),vals.end());
    }

    i=r;j<c;
    int k=0;
    while(i<n && j<n)
    {
        grid[i][j]=vals[k++];
        i++;
        j++;
    }
}

// [00 01 02]
// [10 11 12]
// [20 21 22]
vector<vector<int>> sortMatrix(vector<vector<int>>& grid)
{
    int n=grid.size();
    for(int r=0;r<n;r++)
    {
        sortDiag(grid,r,0,true);
    }
    for(int c=1;c<n;c++)
    {
        sortDiag(grid,0,c,false);
    }
    return grid;
}
int main()
{
    vector<vector<int>> grid={{1,7,3},{9,8,2},{4,5,6}};
    sortMatrix(grid);
    return 0;
}