

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

class PreorderConstruct
{
    public TreeNode buildTree(int[] preorder, int[] inorder) 
    {
        
    }
    public static void main(String[] args) {
        PreorderConstruct s=new PreorderConstruct();
        
        int[] pre = {3,9,20,15,7};
        int[] in  = {9,3,15,20,7};
        TreeNode root = s.buildTree(pre, in);

    }
}