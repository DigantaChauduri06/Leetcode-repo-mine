class Solution:
    def makesquare(self, arr: List[int]) -> bool:
        total = sum(arr)
        if total % 4 != 0:
            return False
        tar = total // 4
        x = tar
        seen = set()
        def combinationSum(i, tar, k, seen):
            if k == 0:
                return True
            if i == len(arr):
                if tar == 0:
                    return combinationSum(0, x, k-1, seen)
                return False
            if tar == 0:
                return combinationSum(0, x, k-1, seen)
            if tar < 0:
                return False
            if i in seen:
                return combinationSum(i+1, tar, k, seen)
            else:
                op1, op2 = False,False
                if tar - arr[i] >= 0:
                    seen.add(i)
                    op1 = combinationSum(i+1, tar - arr[i], k, seen)
                    seen.remove(i)
                while i +1 < len(arr) and arr[i] == arr[i+1]:
                    i += 1
                op2 = combinationSum(i+1, tar, k, seen)
                return op1 or op2
        arr.sort()
        return combinationSum(0, tar, 4, seen)           
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    
                    