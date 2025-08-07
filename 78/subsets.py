from typing import List
class Solution:
    def genSubsets(self,nums:List[int])->List[List[int]]:
        res=[]
        def backtrack(start,arr):
            res.append(arr[:])
            for i in range(start,len(nums)):
                arr.append(nums[i])
                backtrack(i+1,arr)
                arr.pop()

        backtrack(0,[])
        return res
sol=Solution()
nums=[1,2,3]
print(sol.genSubsets(nums))
