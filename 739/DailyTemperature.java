import java.util.ArrayDeque;
import java.util.Deque;

class Solution {
    public int[] dailyTemperatures(int[] t) {
        Deque<Integer> stack=new ArrayDeque<>();
        int n=t.length;
        int[] ans=new int[n];
        for(int i=0;i<n;i++)
        {
            while(!stack.isEmpty() && t[stack.peek()]<t[i])
            {
                int ind=stack.pop();
                ans[ind]=i-ind;
            }
            stack.push(i);
        }
        return ans;
    }
}