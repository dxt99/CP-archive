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

ll n,d;
ll arr[N];
ll dp[N];

ll count(ll src, ll depth){
	if(depth==n)return -1*Mod;
	if(dp[src]!=-1)return dp[src];
	if(arr[src]==0)return dp[src]=0;
	return dp[src]=1+count((src+d)%n,depth+1);
}

void solve(){
	cin>>n>>d;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		dp[i]=-1;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		ll temp=count(i,0);
		ans=max(ans,temp);
		if(temp<0){
			cout<<-1<<endl;
			return;
		}
	}
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
