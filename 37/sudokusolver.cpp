#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution 
{
    public:
    bool isValid(vector<vector<char>>& board,int row,int col,char ch)
    {
        for(int i=0;i<9;i++)
        {
            if(board[row][i]==ch)
            {
                return false;
            }
            if(board[i][col]==ch)
            {
                return false;
            }
            if(board[3*(row/3) + i/3][3*(col/3)+i%3]==ch)
            {
                return false;
            }
        }
    }
    bool solve(vector<vector<char>>& board)
    {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(board[i][j]=='.')
                {
                    for(int ch='1';ch<='9';ch++)
                    {
                        if(isValid(board,i,j,ch))
                        {
                            board[i][j]=ch;
                            if(solve(board))
                            {
                                return true;
                            }
                            else
                            {
                                board[i][j]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board)
    {
        solve(board);
    }
};
int main()
{
    vector<vector<char>> board = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    Solution sol;
    sol.solveSudoku(board);
}