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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=2e5+3;

ll n,k;
ll two;
ll even;
ll dp[maxN][2];

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

ll cnt(ll i,ll eq){
	if(i<0)return 1;
	if(dp[i][eq]!=0)return dp[i][eq];
	ll& ans=dp[i][eq];
	if(!eq){
		ans=two*(cnt(i-1,0));
		ans%=Mod;
	}else if(n&1){
		ans=cnt(i-1,1)*(even+1);
		ans%=Mod;
	}else{
		ans=cnt(i-1,1)*even;
		ans%=Mod;
		ans+=cnt(i-1,0);
		ans%=Mod;
	}
	return ans;
}

void solve(){
	memset(dp,0,sizeof(dp));
	cin>>n>>k;
	even=0;
	for(int i=0;i<n;i+=2){
		even+=C(n,i);
		even%=Mod;
	}
	two=modpow(2,n);
	cout<<cnt(k-1,1)<<endl;
}
 
int main(){
	preprocess();
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	ll t; cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

