# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self,limit):
        if(self.pre >= len(self.preorder)):
            return None
        
        if(self.inorder[self.ino] == limit):
            self.ino+=1
            return None
        
        head = TreeNode(self.preorder[self.pre])
        self.pre+=1
        head.left = self.dfs(head.val)
        head.right = self.dfs(limit)

        return head

    def buildTree(self, preorder: List[int], inorder: List[int]) -> Optional[TreeNode]:
        self.preorder = preorder
        self.inorder = inorder
        self.pre = 0
        self.ino = 0

        return self.dfs(float("inf"))