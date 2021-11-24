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
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=2e5+3;

ll adj[maxN];
ll w[maxN];
int visit[maxN];
vl path;
ll ans=0; 

void dfs(ll i){
	path.pb(i);
	visit[i]=1;
	if(visit[adj[i]]==1){
		int n=path.size()-1;
		ll ret=w[path[n]];
		while(path[n]!=adj[i]){
			ret=min(ret,w[path[n]]);
			n--;
		}
		ret=min(ret,w[path[n]]);
		ans+=ret;
	}
	if(visit[adj[i]]==0){
		dfs(adj[i]);
	}
	visit[i]=2;
}

void solve(){
	ll n; cin>>n;
	for(int i=0;i<n;i++)cin>>w[i+1];
	for(int i=0;i<n;i++)cin>>adj[i+1];
	for(int i=1;i<=n;i++){
		if(visit[i])continue;
		dfs(i);
	}
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

