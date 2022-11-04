n, r = list(map(int, input().split()))
mp = {}
exist = set()
smallest = 99999
cnt = []
idx = []

for i in range(n):
    arr = input().split()
    if arr[0] == "I":
        mp[arr[1]] = [arr[2] ,arr[3], arr[4]] #2 -> huruf , 3->children 1, 4->children 2
        cnt.append(arr[3])
        cnt.append(arr[4])

    if arr[0] == "L":
        mp[arr[1]] = [arr[2], '-1', '-1']
    idx.append(arr[1])

    exist.add(arr[2])
    smallest = min(smallest, int(arr[1]))

root = -1
for i in idx:
    if not i in cnt:
        root = i
        break

for i in range(r):
    strng = input()
    splitted = strng.split()
    sptd = set()
    for i in splitted:
        for j in i:
            if j in exist:
                sptd.add(j)

    lang = []

    st = [mp[root]]

    while st:
        curr = st.pop()
        if curr[1] == '-1':
            lang.append(curr[0])
        else:
            if curr[0] not in sptd:
                st.append(mp[curr[1]])
                st.append(mp[curr[2]])
            else:
                st.append(mp[curr[1]])
    lang.sort()

    print(" ".join(lang))