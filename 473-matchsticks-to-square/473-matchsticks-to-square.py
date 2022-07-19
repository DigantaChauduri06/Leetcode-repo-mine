class Solution:
    def makesquare(self, arr: List[int]) -> bool:
        total = sum(arr)
        if total % 4 != 0:
            return False
        tar = total // 4
        x = tar
        seen = set()
        def combinationSum(i, tar, k):
            if k == 0:
                return True
            if i == len(arr):
                if tar == 0:
                    return combinationSum(0, x, k-1)
                return False
            if tar == 0:
                return combinationSum(0, x, k-1)
            if tar < 0:
                return False
            if i in seen:
                return combinationSum(i+1, tar, k)
            else:
                op1, op2 = False,False
                if tar - arr[i] >= 0:
                    seen.add(i)
                    op1 = combinationSum(i+1, tar - arr[i], k)
                    seen.remove(i)
                while i +1 < len(arr) and arr[i] == arr[i+1]:
                    i += 1
                op2 = combinationSum(i+1, tar, k)
                return op1 or op2
        arr.sort()
        return combinationSum(0, tar, 4)           
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    