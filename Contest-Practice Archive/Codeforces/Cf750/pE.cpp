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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+1;

ll n;
ll arr[maxN];
ll pref[maxN];
ll dp[maxN][450]; //[pos][bef stat] = max sum

void solve(){
	cin>>n;
	for(int i=0;i<=n;i++){
		for(int j=0;j<450;j++)dp[i][j]=-1*Mod;
	}
	for(int i=0;i<n;i++)cin>>arr[i];
	reverse(arr,arr+n);
	for(int i=0;i<=n;i++)pref[i]=0;
	for(int i=1;i<=n;i++)pref[i]=pref[i-1]+arr[i-1]; //pref sum;
	dp[0][0]=Mod;
	for(int i=1;i<=n;i++){
		for(int j=0;j<450&&j<=i;j++){
			dp[i][j]=dp[i-1][j];
			if(j&&i-j>=0&&pref[i]-pref[i-j]<dp[i-j][j-1])
			dp[i][j]=max(dp[i][j],pref[i]-pref[i-j]);
		}
	}
	ll ans=-1;
	for(int i=1;i<450;i++)if(dp[n][i]>0)ans=i;
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

