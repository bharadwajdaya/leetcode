
from typing import List

class Solution:
    def generateParanthesis(self,n:int)->List[str]:
        res=[]
        def backtrack(curr:str,left:int,right:int):
            if n*2==len(curr):
                res.append(curr)
                return
            if left<n:
                backtrack(curr+"(",left+1,right)
            if right<left:
                backtrack(curr+")",left,right+1)

        backtrack("",0,0)
        return res
n=3
sol=Solution()
print(sol.generateParanthesis(n))