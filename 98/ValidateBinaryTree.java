

class TreeNode 
{
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }
    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class ValidateBinaryTree
{
    public boolean helper(TreeNode root,long min_val,long max_val)
    {
        if(root==null)
        {
            return true;
        }
        if((long)root.val <= min_val || (long)root.val>=max_val )
        {
            return false;
        }
        return helper(root.left,min_val,root.val) && helper(root.right,root.val,max_val);
    }
    public boolean isValidBST(TreeNode root) 
    {
        return helper(root,Long.MIN_VALUE,Long.MAX_VALUE);
    }
    public static void main(String[] args) {
        ValidateBinaryTree validateBinaryTree=new ValidateBinaryTree();
        TreeNode root=new TreeNode(5);
        root.left=new TreeNode(1);
        root.right=new TreeNode(4);
        root.right.left=new TreeNode(3);
        root.right.right=new TreeNode(6);
        System.out.println(validateBinaryTree.isValidBST(root));
    }
}