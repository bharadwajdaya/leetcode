import java.util.ArrayDeque;
import java.util.Deque;
import java.util.HashMap;
import java.util.Map;
class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        Map<Integer,Integer> map=new HashMap<>();
        Deque<Integer> stack=new ArrayDeque<>();
        int n=nums1.length;
        int[] ans=new int[n];
        for(int num:nums2)
        {
            while(!stack.isEmpty() && num>stack.peek())
            {
                int smaller=stack.pop();
                map.put(smaller,num);
            }
            stack.push(num);
        }

        while(!stack.isEmpty())
        {
            int num=stack.pop();
            map.put(num,-1);
        }

        for(int i=0;i<n;i++)
        {
            ans[i]=map.getOrDefault(nums1[i],-1);
        }
        return ans;
    }
}