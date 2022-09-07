class Solution:
    def isStackPermutation(self, N : int, A : List[int], B : List[int]) -> int:
        # code here
        stack = deque([])
        i,j = 0,0
        cnt = 0
        while True:
            val = B[j]
            while i < len(A):
                stack.appendleft(A[i])
                if A[i] == val:
                    i+=1
                    break
                i+=1
            while stack and j < len(B) and stack[0] == B[j]:
                j+=1
                cnt += 1
                a = stack.popleft()
            if i >= len(B) or j >= len(A):
                break
        return 1 if cnt == len(A) else 0
    def validateStackSequences(self, pushed: List[int], popped: List[int]) -> bool:
        return self.isStackPermutation(len(pushed), pushed, popped)