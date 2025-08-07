from typing import List
class Solution:
    def combinationSum(self,nums,target):
        res=[]
        def backtrack(curr_sum,ind,arr:List[int]):
            if curr_sum==target:
                res.append(arr[:])
                return
            if curr_sum>target:
                return
            for i in range(ind,len(nums)):
                arr.append(nums[i])
                backtrack(curr_sum+nums[i],i,arr)
                arr.pop()
        backtrack(0,0,[])
        return res

nums=[2,5,6,9]
target=9
sol=Solution()
print(sol.combinationSum(nums,target))
