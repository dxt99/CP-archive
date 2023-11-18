upper = 1e100

start = (2, 3)
vals = []
while True:
    x = min(2 * start[0] ** 2, start[1] ** 2)
    vals.append(x)
    if x > upper:
        break
    start = (start[0] + start[1], 2 * start[0] + start[1])
print(vals[:10])
t = int(input())
for _ in range(t):
    n = int(input())
    i = 0
    for c in vals:
        if c > n:
            break
        i += 1
    print(i)