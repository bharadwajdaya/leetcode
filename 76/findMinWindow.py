from collections import defaultdict
class Solution:
    def findMinWindow(self,s,t):
        s_map=defaultdict(int)
        target=0
        formed=0
        left=0
        right=0
        min_left=0
        min_len=float("inf")
        t_map=defaultdict(int)
        for ch in t:
            t_map[ch]+=1
        target=len(t_map)
        for right,ch in enumerate(s):
            s_map[ch]+=1
            if s_map[ch]==t_map[ch]:
                formed+=1
            while formed==target:
                if right-left+1<min_len:
                    min_len=right-left+1
                    min_left=left
                left_ch=s[left]
                s_map[left_ch]-=1
                if s_map[left_ch]<t_map[left_ch]:
                    formed-=1
                left+=1
        return "" if min_len==float("inf") else s[min_left:min_left+min_len]
sol=Solution()
s="ABOBECODEBANC"
t="ABC"
sol.findMinWindow(s,t)