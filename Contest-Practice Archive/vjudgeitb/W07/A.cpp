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
const int maxN=1e4+3;

vl adj[maxN];
ll ans[maxN];
bool vs[maxN];

void solve(){
	int n,m; cin>>n>>m;
	set<ll> temp[n+1];
	for(int i=0;i<=n;i++){
		adj[i].clear();
		ans[i]=-1;
		vs[i]=0;
	}
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		temp[x].insert(y);
		temp[y].insert(x);
	}
	for(int i=1;i<=n;i++){
		for(auto v:temp[i])adj[i].pb(v);
	}
	int o; cin>>o;
	queue<ll> q;
	q.push(o);
	ans[o]=0;
	vs[o]=1;
	while(!q.empty()){
		int v=q.front(); q.pop();
		for(auto u:adj[v]){
			if(!vs[u]){
				ans[u]=ans[v]+6;
				q.push(u);
				vs[u]=1;
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(i==o)continue;
		cout<<ans[i]<<" ";
	}
	cout<<endl;
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

