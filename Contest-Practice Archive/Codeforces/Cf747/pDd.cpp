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

bool visit1[maxN];
bool visit2[maxN];
vll adj[maxN]; //1:crew 2:imposter
ll stat[maxN];
bool out=0;

bool chk(ll u, pl v){
	if(v.sd<0){
		if(stat[v.fs]==1&&v.sd*-1==stat[u])return 0;
		else if(stat[v.fs]==2&&v.sd*-1!=stat[u])return 0;
		else return 1;
	}else{
		if(stat[u]==1&&v.sd==stat[v.fs])return 0;
		else if(stat[u]==2&&v.sd!=stat[v.fs])return 0;
		else return 1;
	}
}

ll dfs1(ll u,ll k){
	if(out)return 0;
	ll ret=0;
	if(k==2)ret=1;
	visit1[u]=1;
	stat[u]=k;
	for(auto v:adj[u]){
		if(visit1[v.fs]){
			if(chk(u,v)){
			//	cout<<"y"<<u<<v.fs<<v.sd;
				out=1;
				return 0;
			}
			continue;
		}
		if(v.sd<0){
			if(v.sd*-1==k)ret+=dfs1(v.fs,1);
			else ret+=dfs1(v.fs,2);
		}else{
			if(k==1)ret+=dfs1(v.fs,v.sd);
			else if(v.sd==2)ret+=dfs1(v.fs,1);
			else ret+=dfs1(v.fs,2);
		}
	}
	return ret;
}

ll dfs2(ll u,ll k){
	if(out)return 0;
	ll ret=0;
	if(k==2)ret=1;
	visit2[u]=1;
	stat[u]=k;
	for(auto v:adj[u]){
		if(visit2[v.fs]){
			continue;
		}
		if(v.sd<0){
			if(v.sd*-1==k)ret+=dfs2(v.fs,1);
			else ret+=dfs2(v.fs,2);
		}else{
			if(k==1)ret+=dfs2(v.fs,v.sd);
			else if(v.sd==2)ret+=dfs2(v.fs,1);
			else ret+=dfs2(v.fs,2);
		}
	}
	return ret;
}

void solve(){
	out=0;
	ll n,m; cin>>n>>m;
	for(int i=0;i<n;i++){
		visit1[i]=0;
		visit2[i]=0;
		adj[i].clear();
		stat[i]=-1;
	}
	for(int i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		x--; y--;
		string s; cin>>s;
		ll k=1;
		if(s=="imposter")k=2;
		else if(s=="crewmate")k=1;
		adj[x].pb(mp(y,k));
		adj[y].pb(mp(x,-1*k));
		//cout<<x<<" "<<y<<" "<<k<<endl;
	}
	ll ans=0;
	for(int i=0;i<n;i++){
		if(!visit1[i])ans+=max(dfs1(i,1),dfs2(i,2));
	}
	for(int i=0;i<n;i++){
		if(!visit1[i])ans++;
	}
	if(out)ans=-1;
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
