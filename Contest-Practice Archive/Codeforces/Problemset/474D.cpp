#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll k;
ll dp[N];

ll count(){
	for(int i=0;i<k;i++)dp[i]=1;
	for(int i=k;i<maxN;i++){
		dp[i]=dp[i-1]+dp[i-k];
		dp[i]=dp[i]%Mod;
	}
	for(int i=1;i<maxN;i++){
		dp[i]+=dp[i-1];
		dp[i]=dp[i]%Mod;
	}
}

void solve(){
	ll a,b;
	cin>>a>>b;
	ll ans=dp[b]-dp[a-1];
	if(ans<0)ans+=Mod;
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
	cin>>k;
	count();
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
