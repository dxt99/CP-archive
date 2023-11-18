n = int(input())
ori = n
primes = {}
val = 0
for i in range(2, 100000):
    if n%i != 0:
        continue
    primes[i] = 0

    while n%i == 0:
        n/=i;
        primes[i] += 1
    if val != 0 and primes[i] != val:
        print(-1)
        exit(0)
    val = primes[i]

if n != 1:
    print(-1)
    exit(0)


