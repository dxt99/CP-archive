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

vl adj[maxN];
int dist[maxN];
int distb[maxN];
int depth[maxN];

int dfs(int u,int p,int d){
	dist[u]=d;
	depth[u]=dist[u];
	for(auto v:adj[u]){
		if(v==p)continue;
		int k=dfs(v,u,d+1);
		depth[u]=max(depth[u],k);
	}
	return d;
}


void dfsb(int u,int p,int d){
	distb[u]=d;
	for(auto v:adj[u]){
		if(v==p)continue;
		dfsb(v,u,d+1);
	}
}

void solve(){
	int n,x; cin>>n>>x;
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfs(1,-1,0);
	dfsb(x,-1,0);
	int maxi=0;
	for(int i=1;i<=n;i++){
		if(dist[i]>distb[i])maxi=max(maxi,depth[i]);
	}
	cout<<maxi*2<<endl;
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

