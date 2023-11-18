import gmpy2

y = []
for x in range(5, 5000000):
    num = x * (x + 1) // 2
    n, f = gmpy2.iroot(num, 2)
    if n ** 2 == num:
        y.append(x)
        
print(y)