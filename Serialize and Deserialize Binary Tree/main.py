# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Codec:

    # Encodes a tree to a single string.
    def serialize(self, root: Optional[TreeNode]) -> str:
        q = deque()
        result = ""
        q.append(root)

        while q:
            curr = q.popleft()

            if not curr:
                result += "N,"
            else:
                result += f"{curr.val},"
                q.append(curr.left)
                q.append(curr.right)

        return result

    # Decodes your encoded data to tree.
    def deserialize(self, data: str) -> Optional[TreeNode]:
        nodes = data.split(",")
        nodes.pop()

        if nodes[0] == "N":
            return None

        root = TreeNode(int(nodes[0]))

        q = deque()
        q.append(root)
        i = 1

        while q:
            curr = q.popleft()

            if nodes[i] != "N":
                curr.left = TreeNode(int(nodes[i]))
                q.append(curr.left)

            i += 1
            if nodes[i] != "N":
                curr.right = TreeNode(int(nodes[i]))
                q.append(curr.right)

            i += 1

        return root
