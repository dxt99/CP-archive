t = int(input())
for _ in range(t):
    n = int(input())
    c = 0
    while n > 0:
        i = (n+1).bit_length() - 1
        n -= (2 ** i) - 1
        c += 1
    print(c-1)
        