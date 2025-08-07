from typing import List
class Solution:
    def graphValidTree(self,edges,n):
        if not n:
            return True
        adj={i:[] for i in range(n)}
        for node1,node2 in edges:
            adj[node1].append(node2)
            adj[node2].append(node1)

        visit=set()
        def dfs(i,prev):
            if i in visit:
                return False
            visit.add(i)
            for j in adj[i]:
                if j==prev:
                    continue
                if not dfs(j,i):
                    return False
            return True
        if not dfs(0,-1):
            return False
        return len(visit)==n

sol = Solution()
n=5
edges=[[0,1],[0,2],[0,3],[1,4]]
print(sol.graphValidTree(edges,n))