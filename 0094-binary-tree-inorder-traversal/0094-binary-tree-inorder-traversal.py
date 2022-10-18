class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root: return []
        ans = []
        stack = []
        # stack.append(root)
        while True:
            while root:
                stack.append(root)
                root = root.left
            if not stack:
                return ans
            root = stack.pop()
            ans.append(root.val)
            root = root.right
            
        return ans