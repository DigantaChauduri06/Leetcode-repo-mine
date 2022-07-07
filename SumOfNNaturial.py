


def sumOfN(n):
    if n == 1:
        return 1
    small = sumOfN(n - 1)
    return n + small

n = int(input())

print(sumOfN(n))





