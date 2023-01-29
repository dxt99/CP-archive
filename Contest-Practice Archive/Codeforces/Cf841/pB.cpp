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

ll inv(ll i){
	return modpow(i, Mod-2);
}

ll mult(ll a, ll b){
	return (a*b)%Mod;
}

void solve(){
	ll n; cin>>n;
	ll ans = 1;
	ans = mult(ans, n);
	ans = mult(ans, (2*n+1)%Mod);
	ans = mult(ans, n+1);
	ans = mult(ans, inv(6));
	ll ans2=1;
	ans2 = mult(ans2, n-1);
	ans2 = mult(ans2, n);
	ans2 = mult(ans2, n+1);
	ans2 = mult(ans2, inv(3));
	ans = ans + ans2;
	ans%=Mod;
	ans = mult(ans, 2022);
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
