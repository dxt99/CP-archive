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

const int N = 1e6 + 3, Mod = 998244353;
const int maxN=3e3+3;

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

ll P(int a, int b){
	if (a < b) return 0;
    long long ret = (fact[a] * invf[a - b]) % Mod;
    return ret;
}

vl arr(N);
void solve(){
	ll n,m; cin>>n>>m;
	for(int i=0; i<n; i++)cin>>arr[i];
	ll sum=0;
	for(int i=0; i<n; i++)sum+=arr[i];
	if(sum%2){
		ll ans=1;
		for(int i=0; i<n; i++){
			ans=ans*m;
			ans%=Mod;
		}
		cout<<ans<<endl;
		return;
	}
	int l,r;
	l=0;
	r=0;
	ll cnt=0;
	ll diam = 0;
	while(r<n&&l<n){
		while(cnt*2>sum && l<n){
			cnt-=arr[l];
			l++;
		}
		while(cnt*2<sum && r<n){
			cnt+=arr[r];
			r++;
		}
		if(cnt*2==sum && r!=n)diam++;
		if(l<n)cnt-=arr[l];
		l++;
	}
	ll free = n-2*diam;
	ll tot=0;
	for(int i=0; i<=diam; i++){
		if(i>m)break;
		if(i==m && free>0)break;
		ll freecol = m-i;
		ll ans=1;
		// choose diam colors
		/*
		for(int j=i; j>0; j--){
			ans*=(m-j+1);
			ans%=Mod;
		}
		*/
		ans*=C(m, i);
		ans=ans%Mod;
		ans*=fact[i];
		ans=ans%Mod;
		
		ans*=C(diam,i);
		ans%=Mod;
		// choose free diam colors
		/*
		for(int j=diam; j>i; j--){
			ll temp = 1;
			temp *= (freecol);
			temp *= (freecol-1);
			temp = temp%Mod;
			ans*=temp;
			ans=ans%Mod;
		}
		*/
		ans*=modpow(freecol, diam-i);
		ans%=Mod;
		ans*=modpow(freecol-1, diam-i);
		ans%=Mod;
		//cout<<ans<<endl;
		// choose free colors
		/*
		for(int j=0; j<free; j++){
			ans*=freecol;
			ans=ans%Mod;
		}*/
		ans*=modpow(freecol, free);
		ans%=Mod;
		//cout<<ans<<endl;
		tot+=ans;
		tot = tot%Mod;
	}
	cout<<tot<<endl;
}
 
int main(){
	preprocess();
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
