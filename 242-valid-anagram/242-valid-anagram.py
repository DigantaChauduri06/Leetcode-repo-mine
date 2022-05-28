class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        n1 = len(s)
        n2 = len(t)
        s_track = {}
        t_track = {}
        if n1 != n2: 
            return False
        for i in range(n1):
            s_track[s[i]] = 1 + s_track.get(s[i],0)
            t_track[t[i]] = 1 + t_track.get(t[i],0)
        return s_track == t_track