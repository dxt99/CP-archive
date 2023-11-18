n = int(input())

start = 1000000
end = 0

d = input().strip()
dates = [d]
for _ in range(n):
    d = input().strip()
    dates.append(d)

years = [False for i in range(100001)]
bridge = [False for i in range(100001)]

for d in dates:
    l = d.split("-")
    y = int(l[0])
    m = int(l[1])
    years[y] = True
    if m < 3:
        years[y-1] = True
        bridge[y] = True
    start = min(start, y)
    end = max(end, y)

ans = []
for i in range(start, end):
    if bridge[i+1]:
        continue
    ans.append(f"{i+1}-01-01")

print(len(ans))
for c in ans:
    print(c)