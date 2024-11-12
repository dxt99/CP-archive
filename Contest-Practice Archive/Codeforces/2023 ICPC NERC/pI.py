n = int(input())

def recv():
    global k
    i = int(input())
    if i == n:
        exit(0)
    k = i
    return i

k = recv()

def test(idx, cur):
    print(f"{idx} {idx}")
    l = recv()
    if (abs(l-cur)) == 1:
        if l < cur:
            print(f"{idx} {idx}")
            recv()        
        return True
    return False

def gen(idx, cur):
    global k
    if cur == 1:
        yield k
        return
    yield from gen(idx, cur - 1)
    print(f'{cur-1} {idx}')
    recv()
    yield from gen(idx, cur - 1)

def solve(idx):
    if test(idx, k):
        return
    for _ in gen(idx, idx):
        if test(idx, k):
            return
    

for cur in range(n, -1, -1):
    solve(cur)