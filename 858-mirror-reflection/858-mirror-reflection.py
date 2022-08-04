class Solution:
    def mirrorReflection(self, p: int, q: int) -> int:
        return ((p & -p) >= (q & -q)) + ((p & -p) > (q & -q))