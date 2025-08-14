from typing import List
class Solution:
    def bestTime(self,prices:List[int])->int:
        minNum=float("inf")
        maxProfit=float("-inf")
        for n in prices:
            minNum=min(minNum,n)
            if maxProfit<n-minNum:
                maxProfit=n-minNum
        return maxProfit

sol=Solution()
prices = [7,1,5,3,6,4]
print(sol.bestTime(prices))