import java.util.*;

class TreeNode {
    int val;
    TreeNode left, right;
    TreeNode(int v) { val = v; }
}

public class MaximumBinaryTree {

    public static TreeNode constructMaximumBinaryTreeStack(int[] nums) {
        Deque<TreeNode> stack = new ArrayDeque<>();
        for (int num : nums) 
        {
            TreeNode curr = new TreeNode(num);
            while (!stack.isEmpty() && stack.peek().val < num) 
            {
                curr.left = stack.pop();
            }
            if (!stack.isEmpty()) 
            {
                stack.peek().right = curr;
            }
            stack.push(curr);
        }
        while (stack.size() > 1) stack.pop();
        return stack.peek();
    }

    public static void main(String[] args) {
        int[] nums1 = {3,2,1,6,0,5};
        TreeNode r1 = constructMaximumBinaryTreeStack(nums1);
    }
}
