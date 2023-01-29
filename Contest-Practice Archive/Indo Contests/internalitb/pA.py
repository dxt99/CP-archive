def binser(l ,r, a, b, c, d, val):
    mid = (l+r)//2
    f = mid*mid*mid*a + mid*mid*b + mid*c + d
    if (f>val): 
        r = mid-1
    if (f<val):
        l = mid+1
    if (f==val):
        return mid
    return binser(l, r, a, b, c, d, val)

n = int(input())
for _ in range(n):
    s = input().strip().split(" ")
    a = int(s[0])
    b = int(s[1])
    c = int(s[2])
    d = int(s[3])
    val = int(s[4])
    print(binser(0, int(1e15), a, b, c, d, val))