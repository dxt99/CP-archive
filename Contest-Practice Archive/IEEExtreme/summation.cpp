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

const int N = 1e6 + 3, mod = 1e9 + 7;
const int maxN=1e5+3;

long long modpow(long long x, long long y, long long Mod) {
    long long ret = 1;
    while (y > 0) {
        if (y & 1) ret = (ret * x) % Mod;
        y >>= 1;
        x = (x * x) % Mod;
    }
    return ret;
}

ll totient(ll n){
	ll ret=n;
	for(int i=2;i*i<=n;i++){
		if(n%i==0){
			ret-=ret/i;
		}
		while(n%i==0)n/=i;
	}
	return ret;
}

ll gcd(ll a, ll b){
	if(a>b)swap(a,b);
	if(a==0)return b;
	return gcd(b%a,a);
}

void solve(){
	ll n,m,p,q;
	cin>>p>>q>>n>>m;
	ll ans=0;
	ll loop=totient(m);
	loop=m*loop/gcd(m,loop);
    int i=(n/loop)*loop+1;
	for(;i<=n;i++){
		ans=ans+(modpow(p,i,m)*modpow(i,q,m));
		ans=ans%m;
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

