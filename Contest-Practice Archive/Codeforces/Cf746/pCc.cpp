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
const int maxN=2e5+3;

ll n,k;

void solve(){
	cin>>n>>k;
	vl adj[n];
	ll arr[n];
	ll sz[n];	
	ll xr=0;
	bool gone[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		xr=xr^arr[i];
		sz[i]=0;
		gone[i]=0;
	}
	for(int i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		adj[--x].pb(--y);
		adj[y].pb(x);
		sz[x]++;
		sz[y]++;
	}
	if(xr==0){
		cout<<"YES\n";
		return;
	}
	if(xr!=0&&k==2){
		cout<<"NO\n";
		return;
	}
	int found=0;
	for(int i=0;i<n;i++){
		int temp=i;
		while(sz[temp]==1){
			int j=0;
			for(;j<adj[temp].size();j++)if(!gone[adj[temp][j]])break;
			if(arr[temp]==xr){
				found++;
			}else{
				arr[adj[temp][j]]^=arr[temp];
			}
			gone[temp]=1;
			sz[temp]--;
			sz[adj[temp][j]]--;
			//cout<<sz[adj[temp][j]]<<"--"
			temp=adj[temp][j];
		}
	}
	if(found>=2)cout<<"YES\n";
	else cout<<"NO\n";
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
