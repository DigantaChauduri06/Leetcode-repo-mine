class Solution:
    def minMutation(self, start: str, end: str, bank: List[str]) -> int:
        queue, bank = deque([]),set(bank)
        queue.append((start, 0))
        while queue:
            n = len(queue)
            for _ in range(n):
                start,step = queue.popleft()
                if start == end:
                    return step
                for i in range(8):
                    for ch in "ACGT":  
                        good = start[:i] + ch + start[i+1:]
                        if good in bank:
                            queue.append((good, step+1))
                            bank.remove(good)
        return -1