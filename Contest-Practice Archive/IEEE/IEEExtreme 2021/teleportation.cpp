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
const ll INF=1e18;
const int maxN=1e3+3;

ll n,q;
vll adj[maxN];
ll dist[maxN][maxN];

void dfs(ll u, ll p, ll d, ll ori){
	dist[ori][u]=d;
	for(auto v: adj[u]){
		if(v.fs==p)continue;
		dfs(v.fs,u,d+v.sd,ori);
	}
}

void solve(){
	cin>>n>>q;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)dist[i][j]=-1*INF;
	for(int i=0;i<n;i++)dist[i][i]=0;
	for(int i=0;i<n-1;i++){
		ll x,y,w; cin>>x>>y>>w;
		adj[--x].pb(mp(--y,w));
		adj[y].pb(mp(x,w));
	}
	for(int i=0;i<n;i++)dfs(i,-1, 0, i);
	for(int i=0;i<q;i++){
		ll x,y; cin>>x>>y;
		x--; y--;
		ll ans=dist[x][y];
		for(int j=0;j<n;j++){
			ll temp=min(dist[x][j],dist[j][y]);
			ans=max(ans,temp);
		}
		cout<<ans<<endl;
	}
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

