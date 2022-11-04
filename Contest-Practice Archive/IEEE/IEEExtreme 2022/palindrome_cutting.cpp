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
ll prim[N];

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
	prim[0]=1;
	prim[2]=m;
	for(int i=4; i<n+4; i+=4){
		prim[i]=prim[i-2]*m-prim[i/2]+Mod;
		prim[i]%=Mod;
		prim[i+2]=prim[i]*m;
		prim[i+2]%=Mod;
	}
	dp[0]= 1;
	dp[2] = m%Mod;
	for(int i=4; i<=n; i+=2){
		dp[i]=0;
		for(int j=i-2; j>=0; j-=2){
			dp[i] = dp[i] + (dp[j]*prim[i-j])%Mod;
			dp[i] = dp[i]%Mod;
		}
	}
	cout<<dp[n]<<endl;
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
