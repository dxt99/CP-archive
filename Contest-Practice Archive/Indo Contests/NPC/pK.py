primes = []
sumPrimes = [0]
Mod = int(1e9) + 7
def preprocess():
    upper = int(2e6)
    isNotPrime = [False for _ in range(upper)]
    for i in range(2, upper):
        if isNotPrime[i]:
            continue
        primes.append(i)
        sumPrimes.append(i)
        sumPrimes[-1] += sumPrimes[-2]
        for j in range(i*i, upper, i):
            isNotPrime[j] = True

def binser(arr, val):
    l = 0
    r = len(arr)
    while l < r:
        mid = (l + r + 1) // 2
        if arr[mid] <= val:
            l = mid
        else:
            r = mid - 1
    return l

def calc(n):
    if n < 2:
        return 0
    idx = binser(primes, n)
    mididx = (idx + 1) // 2
    befmax = primes[idx - 1] if idx >= 1 else 0
    x = (2 * primes[idx]) // primes[mididx]
    y = (sumPrimes[idx + 1] + befmax + primes[idx]) // (primes[mididx] * 2 + primes[idx])
    z = (sumPrimes[idx + 1] + idx + 1) // (primes[idx] + primes[mididx])
    return pow(x*y, z, Mod)
    

def solve():
    n = int(input())
    arr = []
    for _ in range(2):
        line = input().strip()
        for num in line.split():
            arr.append(int(num))
    assert(len(arr) == 2 * n)
    arr.sort()
    a = sum(arr[:n])//n
    b = sum(arr[n:])//n
    print(min(calc(a), calc(b)))
    

preprocess()
# print(primes[:100])
# print(primes[binser(primes, 6)])
# print(primes[binser(primes, 66)])

t = int(input())
for _ in range(t):
    solve()