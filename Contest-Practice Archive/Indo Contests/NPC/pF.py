def inv(s):
    return ''.join(['1' if i=='0' else '0' for i in s])

def bin2int(s):
    return 0 if len(s) == 0 else int(s, 2)

def solve():
    line = input().strip().split()
    n = int(line[0])
    k = int(line[1])
    l = n.bit_length()
    bitsn = f"{{0:0{l}b}}".format(n)[::-1]
    bitsk = f"{{0:0{l}b}}".format(k)[::-1]
    ans = 0
    
    hold = -1
    state = '1'
    for i in range(l):
        bitn = bitsn[i]
        bitk = bitsk[i]
        
        if bitk == state:
            ans += bin2int(bitsk[i+1:][::-1])
            break
        else:
            ans += (n+(1<<i)) // (1 << (i+1))
            
        if bitn == '1':
            if k == hold:
                print(ans + (n+(1<<i)) // (1 << (i+1)) + 1)
                return
            hold =  bin2int(state + bitsk[:i][::-1])
            state = inv(state)
    print(ans + 1)
    

t = int(input())
for _ in range(t):
    solve()