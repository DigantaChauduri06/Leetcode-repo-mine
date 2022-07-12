def findSubsetsThatSumToK(arr, n, k) :
    res, tmp = [], []
    def helper(i, cur):
        if i == len(arr):
            if len(tmp) > 0 and cur == k:
                res.append(tmp[:])
            return
        tmp.append(arr[i])
        helper(i+1, cur + arr[i])
        tmp.pop()
        helper(i+1, cur)
    helper(0,0)
    if res == []:
        return [[]]
    return res

print(findSubsetsThatSumToK([0, 0, 0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0], 16, 0))
# 16
# 0, 0, ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0 ,0
# 0