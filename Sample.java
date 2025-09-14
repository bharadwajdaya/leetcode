import java.util.*;

class Sample {
    public int minArrivalsToDiscard(int[] arrivals, int w, int m) {
        if (arrivals == null) return 0;
        int n = arrivals.length;
        if (n == 0) return 0;
        if (w <= 0 || m <= 0) return n;

        Map<Integer, Integer> count = new HashMap<>();
        Deque<int[]> window = new ArrayDeque<>(); 
        int ans = 0;

        for (int i = 0; i < n; i++) {
            int val = arrivals[i];

            while (!window.isEmpty() && window.peekFirst()[0] < i - w + 1) {
                int[] old = window.removeFirst();
                int oldVal = old[1];
                int c = count.get(oldVal);
                if (c == 1) count.remove(oldVal);
                else count.put(oldVal, c - 1);
            }

            int curCount = count.getOrDefault(val, 0);
            if (curCount < m) {
                window.addLast(new int[]{i, val});
                count.put(val, curCount + 1);
            } else {
                ans++;
            }
        }

        return ans;
    }

    // for quick local testing
    public static void main(String[] args) {
        Sample s = new Sample();
        int[] arrivals = {1,2,1,3,1};
        System.out.println(s.minArrivalsToDiscard(arrivals, 4, 2)); // prints 2
    }
}
