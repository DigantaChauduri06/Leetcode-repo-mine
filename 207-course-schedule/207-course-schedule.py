class Solution:
    def courseScheduleHelper(self, crs, nodeToMap, visited,n):
        if crs in visited:
            return False
        if nodeToMap[crs] == []:
            return True
        visited.add(crs)
        for pre in nodeToMap[crs]:
            if not self.courseScheduleHelper(pre, nodeToMap, visited, n):
                return False
        visited.remove(crs)
        nodeToMap[crs] = []
        return True
        
    def canFinish(self, n: int, p: List[List[int]]) -> bool:
        nodeToMap = {i: [] for i in range(n+1)}
        for st,ed in p:
            nodeToMap[st].append(ed)
        visited = set()
        for crs in range(n):
            if not self.courseScheduleHelper(crs,nodeToMap, visited, n):
                return False
        return True