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
const int maxN=1e3+3;

ll curId=1;
map<string, int> id;
vl adj[N];
bool vis[N];

ll getId(string s){
	if(id[s]==0)id[s]=curId++;
	return id[s];
}

ll dfs(int i){
	if(vis[i])return 0;
	vis[i]=1;
	ll ret = 1;
	for(auto u: adj[i]){
		ret+=dfs(u);
	}
	return ret;
}

void solve(){
	ll n, m; cin>>n>>m;
	ll ans = (n)*(n-1);
	ans = ans/2;
	for(int i=0; i<m; i++){
		string a; string b;
		cin>>a>>b;
		ll p = getId(a);
		ll q = getId(b);
		adj[p].pb(q);
		adj[q].pb(p);
	}
	for(int i=1; i<=n; i++){
		if(vis[i])continue;
		ll num = dfs(i);
		num*=(num-1);
		num/=2;
		ans-=num;
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
