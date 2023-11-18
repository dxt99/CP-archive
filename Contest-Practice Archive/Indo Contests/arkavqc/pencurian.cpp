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

long long modpow(long long x, long long y) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

void solve(){
	ll n, k; cin>>n>>k;
	if(k==1){
		cout<<0<<endl;
		return;
	}
	if(n==1){
		k %= Mod;
		k = (k + Mod -1) % Mod;
		ll s = k;
		s *= (k+1);
		s %= Mod;
		s *= (2*k+1);
		s %= Mod;
		s *= modpow(6, Mod-2);
		s %= Mod;
		cout<<s<<endl;
		return;
	}
	n %= Mod;
	ll sum = ((n+Mod-1)%Mod) * modpow(n, k);
	sum = sum % Mod;
	sum *= modpow(((k%Mod + Mod - 1) % Mod), 2);
	sum %= Mod;
	
	sum += Mod - n;
	sum %= Mod;
	sum += Mod - 2;
	sum %= Mod;

	ll poly = 2;
	poly *= (modpow(n + Mod - 1, Mod - 2));
	poly %= Mod;
	poly *= ((modpow(n, k) + Mod -1) % Mod);
	poly %= Mod;
	sum += poly;
	sum %= Mod;
	
	ll neg = (Mod-1) * modpow(n, k);
	neg %= Mod;
	neg *= ((2*(k%Mod) + Mod - 3) % Mod);
	neg %= Mod;
	
	sum += neg;
	sum %= Mod;

	ll inv = modpow(n + Mod -1, Mod-2);
	inv = (inv * inv)%Mod;
	
	sum*=inv;
	sum%=Mod;
	
	cout<<sum<<endl;
	
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
