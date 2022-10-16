roman_numerals = {
    "I":1,
    "V":5,
    "X":10,
    "L":50,
    "C":100,
    "D":500,
    "M":1000
}

class Solution:
    def romanToInt(self, s: str) -> int:
        """
            XVIII = 1 + 1 + 1 + 5 + 10 = 18
            IV == V - I = 4
            VI == V + I = 6
            MCMXCIV = 
        """
        ans,prev = 0,0
        for c in s[::-1]:
            if prev <= roman_numerals[c]:
                ans += roman_numerals[c]
            else:
                ans -= roman_numerals[c]
            prev = roman_numerals[c]
        return ans
        