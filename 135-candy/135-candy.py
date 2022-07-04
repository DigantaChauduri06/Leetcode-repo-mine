class Solution:
    def candy(self, ratings: List[int]) -> int:
        n = len(ratings)
        LeftDis = [1] * n
        RightDis = [1] * n
        for i in range(1, n):
            if ratings[i] > ratings[i-1]:
                LeftDis[i] = max(LeftDis[i-1], LeftDis[i]) + 1
        for i in range(n-2, -1,-1):
            if ratings[i+1] < ratings[i]:
                RightDis[i] = max(RightDis[i+1], RightDis[i]) + 1
        totalCandy = 0
        for can1, can2 in zip(LeftDis, RightDis):
            totalCandy += max(can1, can2)
        return totalCandy
    
    


"""
    [1,0,2] -> [(1,0), (0,1), (2,2)] -> [(0,1),(1,0), (2,2)]
    [1,1,1]
      

"""