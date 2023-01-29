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

ll dp[maxN][2]; //max, min
void solve(){
	ll n; cin>>n;
	ll p; cin>>p;
	dp[0][0]=p;
	dp[0][1]=p;
	for(int i=1; i<=n; i++){
		char c; cin>>c;
		ll val; cin>>val;
		if (c=='+'){
			dp[i][0]=max(dp[i-1][0]+val, dp[i-1][1]+val);
			dp[i][1]=min(dp[i-1][0]+val, dp[i-1][1]+val);
		}else{
			dp[i][0]=max(dp[i-1][0]*val, dp[i-1][1]*val);
			dp[i][1]=min(dp[i-1][0]*val, dp[i-1][1]*val);
		}
		cin>>c; cin>>val;
		if (c=='+'){
			ll temp=max(dp[i-1][0]+val, dp[i-1][1]+val);
			dp[i][0]=max(dp[i][0], temp);
			temp=min(dp[i-1][0]+val, dp[i-1][1]+val);
			dp[i][1]=min(dp[i][1], temp);
		}else{
			ll temp=max(dp[i-1][0]*val, dp[i-1][1]*val);
			dp[i][0]=max(dp[i][0], temp);
			temp=min(dp[i-1][0]*val, dp[i-1][1]*val);
			dp[i][1]=min(dp[i][1], temp);
		}
	}
	cout<<dp[n][0]<<endl;
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
