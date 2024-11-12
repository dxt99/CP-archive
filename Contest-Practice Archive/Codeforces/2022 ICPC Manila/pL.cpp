#include<bits/stdc++.h>

using namespace std;

long long powmod(long long a, long long b, long long m) {
    long long res = 1;
    while (b > 0) {
        if (b & 1) {
            res = (res * 1ll * a) % m;
        }
        a = (a * 1ll * a) % m;
        b >>= 1;
    }
    return res;
}

// Returns minimum x for which k * a ^ x % m = b % m.
long long pollig(long long a, long long b, long long m, long long k = 1) {
    a %= m, b %= m;
    long long add = 0, g;
    while ((g = gcd(a, m)) > 1) {
        if (b == k)
            return add;
        if (b % g)
            return -1;
        b /= g, m /= g, ++add;
        k = (k * 1ll * a / g) % m;
    }

    long long n = sqrt(m) + 1;
    long long an = 1;
    for (long long i = 0; i < n; ++i)
        an = (an * 1ll * a) % m;

    unordered_map<long long, long long> vals;
    for (long long q = 0, cur = b; q <= n; ++q) {
        vals[cur] = q;
        cur = (cur * 1ll * a) % m;
    }

    for (long long p = 1, cur = k; p <= n; ++p) {
        cur = (cur * 1ll * an) % m;
        if (vals.count(cur)) {
            long long ans = n * p - vals[cur] + add;
            return ans;
        }
    }
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
    long long n; cin>>n;
    for(long long i=0; i<n; i++){
        long long a,b,s,p,v;
        cin>>a>>b>>s>>p>>v;
        if (s==v){
            cout<<0<<endl;
            continue;
        }
        if (a == 1){
            // s + b*k = v
            // k = (v - s) * inv(b)
            long long invb = powmod(b, p-2, p);
            invb *= ((v-s + p) % p);
            invb %= p;
            cout<<invb<<endl;
            continue;
        }
        long long up = (v * 1ll * (a-1ll)) % p;
        up += b;
        up %= p;
        long long down = (s * 1ll * (a-1ll)) % p;
        down += b;
        down %= p;
        long long ans = pollig(a, up, p, down);
        if (ans == -1) cout<<"IMPOSSIBLE"<<endl;
        else cout<<(ans)<<endl;
    }
    return 0;
}