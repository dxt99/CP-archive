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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

//fast C(N,K)
long long fact[N], invf[N], inv[N];

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

void preprocess() {
    fact[0] = invf[0] = 1;
    for (int i = 1; i < N; i++) {
        fact[i] = (fact[i - 1] * i) % Mod;
        invf[i] = modpow(fact[i], Mod - 2);
        inv[i]=modpow(i,Mod-2);
    }
}

long long C(int a, int b) {
    if (a < b) return 0;
    long long ret = (fact[a] * invf[a - b]) % Mod;
    ret = (ret * invf[b]) % Mod;
    return ret;
}

void solve(){
	ll n; ll m; cin>>n>>m;
	ll ans=1;
	for(int i=0; i<m; i++){
		ll t; cin>>t;
		ans *= C(n,t);
		ans %= Mod;
		n-=t;
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	preprocess();
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
