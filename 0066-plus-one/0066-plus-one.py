class Solution:
    def plusOne(self, digits: List[int]) -> List[int]:
        digits[-1] += 1
        carry = digits[-1] // 10
        digits[-1] = digits[-1] % 10
        if carry == 0:
            return digits
        i = len(digits) - 2
        while i >= 0 and carry:
            digits[i] += carry
            carry = digits[i] // 10
            if carry == 0:
                break
            digits[i] = digits[i] % 10
            i-=1
        if carry != 0:
            digits[0] = digits[0] % 10
            digits.insert(0, carry)
        return digits