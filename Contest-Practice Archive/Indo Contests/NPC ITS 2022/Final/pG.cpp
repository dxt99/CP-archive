#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef vector<ll> vl;
typedef pair<ll,ll> pl;
typedef vector<pair<ll,pl>> vll;

const int N = 1e6+3;
const int Mod = 1e9+7;

ll fact[N], invf[N], inv[N];

ll modpow(ll x, ll y){
	ll ret = 1;
	while(y>0){
		if(y&1)ret=(ret*x)%Mod;
		y>>=1;
		x=(x*x)%Mod;
	}
	return ret;
}

void preprocess(){
	fact[0]=invf[0]=1;
	for(int i=1; i<N; i++){
		fact[i] = (fact[i-1] * i) % Mod;
		invf[i] = modpow(fact[i], Mod - 2);
		inv[i] = modpow(i, Mod-2);
	}
}

int main(){
	preprocess();
	ll m,n; cin>>m>>n;
	n+=1;
	vl arr(m);
	for(int i=0;i<m; i++)cin>>arr[i];
	ll cur = 1;
	ll ans = 0;
	for(int i=0;i<m; i++){
		n--;
		cur = cur * (n%Mod);
		cur = cur % Mod;
		cur = (cur * inv[i+1])%Mod;
		arr[i] %= Mod;
		ans += (cur*arr[i])%Mod;
		ans %= Mod;
	}
	cout<<ans<<endl;
}

