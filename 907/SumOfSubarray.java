class Solution {
    public int sumSubarrayMins(int[] arr) {
        final long MOD = 1_000_000_007L;
        int n = arr.length;
        int[] prevLess = new int[n];
        int[] nextLessEqual = new int[n];   

        Deque<Integer> stack = new ArrayDeque<>();
        for (int i = 0; i < n; i++) {
            while (!stack.isEmpty() && arr[stack.peek()] >= arr[i]) {
                stack.pop();
            }
            prevLess[i] = stack.isEmpty() ? -1 : stack.peek();
            stack.push(i);
        }

        stack.clear();
        for (int i = n - 1; i >= 0; i--) {
            while (!stack.isEmpty() && arr[stack.peek()] > arr[i]) {
                stack.pop();
            }
            nextLessEqual[i] = stack.isEmpty() ? n : stack.peek();
            stack.push(i);
        }

        long result = 0;
        for (int i = 0; i < n; i++) {
            long leftCount = i - prevLess[i];
            long rightCount = nextLessEqual[i] - i;
            long contrib = ((long) arr[i] * leftCount) % MOD;
            contrib = (contrib * rightCount) % MOD;
            result = (result + contrib) % MOD;
        }

        return (int) result;
        
    }
}