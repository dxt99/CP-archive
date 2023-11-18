#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3;
const int maxN=1e3+3;
vl primes;
bool notPrime[N];
map<ll, ll> totMap;

int gcd(int a, int b){
	if (a<b) return gcd(b, a);
	if (b==0) return a;
	return gcd(b, a%b);
}

int phi(int n)
{
    // Initialize result as n
    int result = n;
  
    // Consider all prime factors of n
    // and subtract their multiples
    // from result
    for(auto p: primes)
    {
         
        // Check if p is a prime factor.
        if (n % p == 0)
        {
             
            // If yes, then update n and result
            while (n % p == 0)
                n /= p;
                 
            result -= result / p;
        }
    }
  
    // If n has a prime factor greater than sqrt(n)
    // (There can be at-most one such prime factor)
    if (n > 1)
        result -= result / n;
         
    return result;
}

long long modpow(long long x, long long y, long long Mod) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

ll countPow(ll k, ll mod){
	if (!totMap[mod]){
		totMap[mod] = phi(mod);
	}
	ll tot = totMap[mod];
	ll power = modpow(10, 100, tot);
	return modpow(k, power, mod);
}

int count(ll i, ll k, ll n){
	if (!totMap[n]){
		totMap[n] = phi(n);
	}
	ll tot = totMap[n];
	ll gc = gcd(k, tot);
	ll power = (countPow(k/gc, tot/gc) * gc) % tot;
	return modpow(i, power, n);
}

void solve(){
	int n, k; cin>>n>>k;
	notPrime[0] = 1;
	notPrime[1] = 1;
	for(ll i=2; i<N; i++){
		if(notPrime[i]) continue;
		primes.pb(i);
		for(ll j=i*i; j<N; j+=i)notPrime[j]=1;
	}
	
	ll ans = 1;
	for(int i=2; i<n; i++){
		int gc = gcd(i, n);
		int j = i/gc;
		cout<<(count(j, k, n/gc) * gc) % n<<endl;
		ans += (count(j, k, n/gc) * gc) % n;
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
//	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
