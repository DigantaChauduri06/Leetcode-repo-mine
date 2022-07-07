def isPalindrome(s: str) -> bool:
    def helper(si, ei):
        if si >= ei:
            return True
        if s[si] != s[ei]:
            return False
        if not helper(si+1, ei-1):
            return False
        return True
    return helper(0, len(s) - 1)


print(isPalindrome("racecar"))