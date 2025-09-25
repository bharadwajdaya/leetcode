import java.util.*;
class Solution {
    public int networkDelayTime(int[][] times, int n, int k) {
        List<int[]>[] arrlist=new ArrayList[n+1];
        for(int i=1;i<=n;i++)
        {
            arrlist[i]=new ArrayList<>();
        }
        for(int[] t:times)
        {
            int u=t[0];
            int v=t[1];
            int w=t[2];
            arrlist[u].add(new int[]{v,w});
        }

        int[] dist=new int[n+1];
        Arrays.fill(dist,Integer.MAX_VALUE);
        dist[k]=0;

        PriorityQueue<int[]> pq=new PriorityQueue<>(Comparator.comparingInt(a-> a[0]));
        pq.offer(new int[]{0,k});

        boolean[] seen=new boolean[n+1];
        while(!pq.isEmpty())
        {
            int[] top=pq.poll();
            int d=top[0];
            int node=top[1];
            if(seen[node])
            {
                continue;
            }
            seen[node]=true;
            for(int[] edge:arrlist[node])
            {
                int nei=edge[0];
                int w=edge[1];
                if(dist[nei]>d+w)
                {
                    dist[nei]=d+w;
                    pq.offer(new int[]{dist[nei],nei});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==Integer.MAX_VALUE)
            {
                return -1;
            }
            ans=Math.max(ans,dist[i]);
        }
        return ans;
    }
}