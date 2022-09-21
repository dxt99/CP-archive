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

const int N = 1e6 + 3, Mod = 998244353;
const int maxN=1e3+3;

ll n,k;
ll dp[maxN][maxN];
pl cnt[maxN];

ll count(ll pos,ll sum){
	if(sum==k)return 1;
	if(sum>k)return 0;
	if(pos==n)return 0;
	if(dp[pos][sum]!=-1)return dp[pos][sum];
	ll& ans=dp[pos][sum];
	ans=0;
	for(ll i=0;i<=cnt[pos].fs&&sum+i*cnt[pos].sd<=k;i++){
		ans+=count(pos+1,sum+i*cnt[pos].sd);
		ans%=Mod;
	}
	
	return ans;
}

void solve(){
	cin>>n>>k;
	for(int i=0;i<n;i++){
		ll x,y; cin>>x>>y;
		cnt[i]=mp(x,y);
		for(int j=0;j<k;j++)dp[i][j]=-1;
	}
	cout<<count(0,0)<<endl;
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

