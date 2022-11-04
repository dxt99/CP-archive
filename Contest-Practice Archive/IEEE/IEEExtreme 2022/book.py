import re
p = int(input())
n = int(input())
R,C = input().split(",")
R = int(R)
C = int(C)
S = input()

plain = []
for _ in range(p):
    plain.append(input())

s = ""

for _ in range(n):
    text = input()
    text = re.sub('<[^>]*>', "", text)
    s = s + (text)
maxi = R*C
s = s[:maxi]
for text in plain:
    i = 0
    ans = ""
    for c in text:
        if i!=0:
            ans+=","
        i+=1
        if c not in s:
            ans = "0"
            break
        if S=="S":
            idx = s.find(c)
        else:
            idx = s.rfind(c)
        idx = int(idx)
        idxR = idx//C + 1
        idxL = idx%C + 1
        ans += str(idxR)
        ans += ","
        ans += str(idxL)
        assert(idxR<=R and idxL<=C)
    print(ans)