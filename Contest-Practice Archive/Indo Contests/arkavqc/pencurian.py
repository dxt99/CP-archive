M = int(1e9+7)
def form(n, k):
    n = n % M
    ans = (n-1) * pow(n, k, M) * pow(k-1, 2, M) - n - 2 + 2 * (pow(n, k, M) - 1) * pow(n-1, -1, M) - (2*k - 3) * pow(n, k, M)
    ans %= M
    ans = ans * pow(n-1, -2 , M)
    ans %= M
    return ans

def brute(n, k):
    ans = 0
    for i in range(k):
        ans += (pow(i, 2, M) * pow(n, i, M))
        ans %= M
    return ans

payload = int(1e11+23453642342)
print(payload)
print(form(payload, payload))