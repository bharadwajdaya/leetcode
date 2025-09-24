

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

class Kthsmallest
{
    public void inorder(TreeNode root,List<Integer> list)
    {
        if(root==null)
        {
            return ;
        }
        inorder(root.left,list);
        list.add(root.val);
        inorder(root.right,list);
    }
    public int kthSmallest(TreeNode root, int k) 
    {
        List<Integer> list=new ArrayList<>();
        inorder(root,list);
        return list[k-1];
    }
   
    public static void main(String[] args) {
        Kthsmallest kth=new Kthsmallest();
        TreeNode root=new TreeNode(10);
        root.left=new TreeNode(1);
        root.right=new TreeNode(5);
        root.right.left=new TreeNode(2);
        root.right.right=new TreeNode(6);
        System.out.println(kth.kthSmallest(root,3));
    }
}