class Solution:
    def postorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        if not root:
            return []
        stack1,stack2 = [],[]
        stack1.append(root)
        while stack1:
            r = stack1.pop()
            stack2.append(r.val)
            if r.left:
                stack1.append(r.left)
            if r.right:
                stack1.append(r.right)
        stack2.reverse()
        return stack2