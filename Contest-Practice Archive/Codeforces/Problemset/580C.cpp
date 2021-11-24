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
const int maxN=1e3+3;

int n,m;
vll adj[N];
bool visited[N];
int w[N];
ll ans=0;

void dfs(ll v, ll cur, ll cons, bool bef){
	visited[v]=1;
	if(w[v-1]&&bef)cur++;
	else cur=w[v-1];
	cons=max(cons,cur);
	if(w[v-1])bef=1;
	if(v!=1&&adj[v].size()==1&&cons<=m)ans++;
	for(auto i: adj[v]){
		if(!visited[i.fs])dfs(i.fs,cur,cons,bef);
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>w[i];
	for(int i=0;i<n-1;i++){
		int x,y;
		cin>>x>>y;
		adj[x].pb(mp(y,0));
		adj[y].pb(mp(x,0));
	}
	dfs(1,0,0,0);
	cout<<ans<<endl;
}
