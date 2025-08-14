from typing import List
class Solution:
    def isValidSudoku(self,board:List[List[str]])->bool:
        row=[set() for _ in range(9)]
        col=[set() for _ in range(9)]
        part=[set() for _ in range(9)]

        for r in range(9):
            for c in range(9):
                ch=board[r][c]
                if ch==".":
                    continue

                if ch in row[r]:
                    return False
                row[r].add(ch)

                if ch in col[c]:
                    return False
                col[c].add(ch)

                b=(r//3)*3+(c//3)
                if ch in part[b]:
                    return False
                part[b].add(ch)
        return True


sol=Solution()
board=[["5","3",".",".","7",".",".",".","."]
,["6",".",".","1","9","5",".",".","."]
,[".","9","8",".",".",".",".","6","."]
,["8",".",".",".","6",".",".",".","3"]
,["4",".",".","8",".","3",".",".","1"]
,["7",".",".",".","2",".",".",".","6"]
,[".","6",".",".",".",".","2","8","."]
,[".",".",".","4","1","9",".",".","5"]
,[".",".",".",".","8",".",".","7","9"]]
print(sol.isValidSudoku(board))