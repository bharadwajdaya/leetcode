import java.util.ArrayDeque;
import java.util.Arrays;
import java.util.Deque;

public class DailyTemperature
{
    public int[] dailyTemperatures(int[] t) {
        int n=t.length;
        int[] ans=new int[n];
        Deque<Integer> stack=new ArrayDeque<>();
        for(int i=0;i<n;i++)
        {
            while(!stack.isEmpty() && t[stack.peek()]<t[i])
            {
                int _ind=stack.pop();
                ans[_ind]=i-_ind;
            }
            stack.push(i);
        }
        return ans;
    }
    public static void main(String[] args)
    {
        DailyTemperature dt=new DailyTemperature();
        int[] t={73,74,75,71,69,72,76,73};
        Arrays.stream(dt.dailyTemperatures(t)).forEach(e-> System.out.print(e));
    }
}
