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

ll stat[maxN];
vl adj[maxN];
pl tot[maxN];
ll par[maxN];

void preprocess(ll u, ll p){
	par[u]=p;
	if(stat[u])tot[u].sd++;
	else tot[u].fs++;
	for(auto i:adj[u]){
		if(i==p)continue;
		preprocess(i,u);
		tot[u].fs+=tot[i].fs;
		tot[u].sd+=tot[i].sd;
	}
}

void update(ll u){
	if(u==-1)return;
	if(stat[u])tot[u]=mp(0,1);
	else tot[u]=mp(1,0);
	for(auto i:adj[u]){
		if(i==par[u])continue;
		tot[u].fs+=tot[i].fs;
		tot[u].sd+=tot[i].sd;
	}
	update(par[u]);
}

void solve(){
	ll n; cin>>n;
	for(int i=0;i<n;i++)cin>>stat[i];
	for(int i=0;i<n;i++)tot[i]=mp(0,0);
	for(int i=0;i<n;i++)par[i]=-1;
	for(int i=0;i<n;i++)adj[i].clear();
	for(int i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
	preprocess(0,-1);
	ll q; cin>>q;
	for(int i=0;i<q;i++){
		ll x; cin>>x;
		if(x==1){
			ll y; cin>>y;
			stat[y-1]^=1;
			update(y-1);
		}else{
			ll a,b; cin>>a>>b;
			a--; b--;
			ll pa=par[a];
			ll pb=par[b];
			while(pa!=-1&&pa!=b)pa=par[pa];
			while(pb!=-1&&pb!=a)pb=par[pb];
			ll tota=0;
			ll totb=0;
			if(pa==pb){
				tota=tot[a].fs*tot[b].fs;
				totb=tot[a].sd*tot[b].sd;
			}else if(pa==b){
				tota=tot[a].fs*(tot[0].fs-tot[b].fs+(ll)(stat[b]^1));
				totb=tot[a].sd*(tot[0].sd-tot[b].sd+(ll)stat[b]);
			}else if(pb==a){
				tota=tot[b].fs*(tot[0].fs-tot[a].fs+(ll)(stat[a]^1));
				totb=tot[b].sd*(tot[0].sd-tot[a].sd+(ll)stat[a]);
			}
			cout<<tota<<"--"<<totb<<endl;
			if(tota>totb)cout<<"A\n";
			else if(tota<totb)cout<<"B\n";
			else cout<<"TIE\n";
		}
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

