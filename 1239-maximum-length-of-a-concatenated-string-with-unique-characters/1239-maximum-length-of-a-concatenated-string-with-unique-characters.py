"""
    ["un","iq","ue"]
--> [""]
--> ["un"]
"""
class Solution:
    def maxLength(self, arr: List[str]) -> int:
        mxLen = 0
        track = set()
        def helper(i, tmp):
            nonlocal mxLen
            if i == len(arr):
                mxLen = max(mxLen, len(tmp))
                return
            # non-skip
            canPick = True
            # if cur element has duplicate
            for chars in arr[i]:
                if chars in track:
                    canPick = False
                track.add(chars)
            track.clear()
            if canPick:
                # if the cur element has a char which also exists in tmp
                for chars in tmp:
                    track.add(chars)
                
                for chars in arr[i]:
                    if chars in track:
                        canPick = False
                        break
                track.clear()
            if canPick:
                helper(i+1, tmp + arr[i])
            #skip
            helper(i+1, tmp)
        
        helper(0, "")
        return mxLen