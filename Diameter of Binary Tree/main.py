# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def height(self, root):
        if not root:
            return 0

        left = self.height(root.left)
        right = self.height(root.right)
        self.maxHeight = max(self.maxHeight, left + right)

        return 1 + max(left, right)

    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        self.maxHeight = 0

        self.height(root)

        return self.maxHeight
