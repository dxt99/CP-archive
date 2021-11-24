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
const int maxN=3e5+3;

vl adj[maxN];
int px,py;

void dfsx(int u,int p,int t){
	if(px)return;
	for(auto v:adj[u]){
		if(v==p)continue;
		if(v==t){
			px=u;
			return;
		}
		dfsx(v,u,t);
	}
}

void dfsy(int u,int p,int t){
	if(py)return;
	for(auto v:adj[u]){
		if(v==p)continue;
		if(v==t){
			py=u;
			return;
		}
		dfsy(v,u,t);
	}
}

ll dfs(int u,int p){
	ll ret=1;
	for(auto v:adj[u]){
		if(v==p)continue;
		ret+=dfs(v,u);
	}
	return ret;
}

void solve(){
	int n,x,y; cin>>n>>x>>y;
	for(int i=0;i<n-1;i++){
		int a,b; cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}
	dfsx(x,-1,y);
	dfsy(y,-1,x);
	ll cntl=dfs(x,py);
	ll cntr=dfs(y,px);
	ll ans=(ll)n;
	ans=(ans-1)*ans;
	ans-=cntl*cntr;
	cout<<ans<<endl;
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

