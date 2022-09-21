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
const int maxN=1e5+3;

vl adj[maxN];
bool vis[maxN];

void dfs(int u, int p){
	vis[u]=1;
	for(auto v:adj[u]){
		if(vis[v])continue;
		dfs(v,u);
	}
}

void solve(){
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	if(n!=(m+1)){
		cout<<"NO"<<endl;
		return;
	}
	dfs(1,-1);
	for(int i=1;i<=n;i++){
		if(!vis[i]){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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

