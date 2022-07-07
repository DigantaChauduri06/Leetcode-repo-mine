res = []
def generatePermutations(s, idx = 0):
    # write your code here
    if idx == len(s):
        res.append("".join(s))

    for i in range(idx, len(s)):
        s[i], s[idx] = s[idx],s[i]
        generatePermutations(s, idx+1)
        s[i], s[idx] = s[idx],s[i]


generatePermutations(list("abc"))
print(res)