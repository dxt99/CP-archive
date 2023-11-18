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

vl val(N, 0);
vl adj[N];
vl deg(N, 0);

void solve(){
	ll n,m; cin>>n>>m;
	ll arr[n];
	for(int i=0; i<n; i++)cin>>arr[i];
	for(int i=0; i<n; i++){
		int x; cin>>x;
		val[x] += arr[i];
	}
	
	for(int i=1; i<m; i++){
		int u, v; cin>>u>>v;
		adj[u].pb(v);
		deg[v]++;
	}
	vl cut;
	for(int i=1; i<=m; i++)if(!deg[i])cut.pb(i);
	
	while(cut.size()>0){
		vl temp;
		for(auto c:cut){
			for(auto d: adj[c]){
				deg[d]--;
				if(!deg[d])temp.pb(d);
				val[d]+=val[c];
			}
		}
		cut.clear();
		for(auto c: temp)cut.pb(c);
	}
	ll maxi=0;
	for(int i=1; i<=m; i++){
		maxi = max(val[i], maxi);	
	}
	vl ans;
	for(int i=1; i<=m; i++){
		if(val[i]==maxi)ans.pb(i);
	}
	cout<<ans.size()<<endl;
	for(auto c: ans)cout<<c<<" ";
	cout<<endl;
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
