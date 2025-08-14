# 0 1 2 3 4 5 6 7
# a b c a b c b b

# a:0,3
# b:1,4,6,7
# c:2,5
from collections import defaultdict
from typing import List
class Solution:
    def lengthOfLongestSubstring(self,s:str)->int:
        d={}
        maxLen=0
        start=0
        for i,ch in enumerate(s):
            if ch in d and d[ch]>=start:
                start=d[ch]+1
            d[ch]=i
            maxLen=max(maxLen,i-start+1)
        return maxLen

sol=Solution()
s="abcabcbb"
print(sol.lengthOfLongestSubstring(s))
