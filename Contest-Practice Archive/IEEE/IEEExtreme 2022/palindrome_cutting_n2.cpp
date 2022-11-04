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
const int maxN=1e3+3;
ll dp[N];
ll sum[N];

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
	ll n,m; cin>>n>>m;
	dp[2] = m;
	dp[4] = 2*modpow(m,2) - m;
	if(dp[4]<0)dp[4]+=Mod;
	dp[4]%=Mod;
	for(int i=6; i<=n; i+=2){
		dp[i] = (dp[i-2]*((2*m)%Mod));
		dp[i]%=Mod;
		dp[i] -= ((dp[i-4] * modpow(m,2))%Mod);
		if(dp[i]<0)dp[i]+=Mod;
		dp[i]%=Mod;
		dp[i]+=(modpow(m, i/2-1)*(m-1));
		dp[i]%=Mod; 
	}
	cout<<dp[n]<<endl;
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
