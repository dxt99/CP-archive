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

void solve(){
	int n; cin>>n;
	map<int,int> mp;
	vl arr(n+1);
	for(int i=1; i<=n; i++)cin>>arr[i];
	vl pre(n+1); pre[1]=arr[1];
	for(int i=2; i<=n ;i++)pre[i]=pre[i-1]^arr[i];
	vl dp(n+1);
	dp[0]=0;
	for(int i=1; i<=n; i++){
		dp[i]=dp[i-1]+1;
		if(mp[pre[i]]!=0 || pre[i]==0)dp[i]=min(dp[i], dp[mp[pre[i]]]+(i-mp[pre[i]]-1));
		mp[pre[i]]=i;
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
