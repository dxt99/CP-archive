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
const int maxN=1e5+3;

vl adj[maxN];
int col[maxN];
int cnt[3];
bool f=1;

int xxor(int a){
	if(a==1)return 2;
	else return 1;
}

bool dfs(int u){
	for(auto v:adj[u]){
		if(col[v]==0){
			col[v]=xxor(col[u]);
			cnt[col[v]]++;
			if(!dfs(v))return 0;
		}
		else if(col[v]!=xxor(col[u])){
			f=0;
			return 0;
		}
	}
	return 1;
}

void solve(){
	int n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	for(int i=1;i<=n;i++){
		if(col[i]==0){
			cnt[1]++;
			col[i]=1;
			dfs(i);
		}
	}
	if(!f)cout<<-1<<endl;
	else{
		cout<<cnt[1]<<endl;
		for(int i=1;i<=n;i++){
			if(col[i]==1)cout<<i<<" ";
		}
		cout<<endl;
		cout<<cnt[2]<<endl;
		for(int i=1;i<=n;i++){
			if(col[i]==2)cout<<i<<" ";
		}
		cout<<endl;
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

