from typing import Optional

class TreeNode:
    def __init__(self, val: int = 0, left: Optional['TreeNode'] = None, right: Optional['TreeNode'] = None):
        self.val = val
        self.left = left
        self.right = right


class Solution:
    def tree2str(self, t: Optional[TreeNode]) -> str:
        if not t:
            return ""

        s = str(t.val)
        if t.left or t.right:
            s += "(" + self.tree2str(t.left) + ")"

        if t.right:
            s += "(" + self.tree2str(t.right) + ")"

        return s


if __name__ == "__main__":
    root = TreeNode(1)
    root.left = TreeNode(2)
    root.left.right = TreeNode(4)
    root.right = TreeNode(3)

    sol = Solution()
    print(sol.tree2str(root))
