# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def dfs(self,node:TreeNode, currMax: int) -> None:
        if(not node): return

        if(node.val >= currMax):
            self.result+=1
        
        currMax = max(currMax,node.val)
        self.dfs(node.left,currMax)
        self.dfs(node.right,currMax)

    def goodNodes(self, root: TreeNode) -> int:
        self.result = 0
        self.dfs(root,float("-inf"))

        return self.result