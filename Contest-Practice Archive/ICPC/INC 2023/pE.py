p = 3394302287

def hsh(s):
    sum = 0
    for i, c in enumerate(s):
        sum += pow(2, (ord(c) - ord("A") + 1), p)
    return sum

n = int(input())
tar = str(input())[::-1]
mp = set()
cur = 0
for c in tar:
    cur += hsh(c)
    mp.add(cur)
    
q = int(input())
for _ in range(q):
    s = str(input())
    known = 0
    cur = ""
    for c in s:
        cur += c
        cur_hsh = hsh(cur)
        hh = known + cur_hsh
        if known in mp:
            known = hh
            cur = ""
    if len(cur) == 0:
        print("YES")
    else:
        print("NO")