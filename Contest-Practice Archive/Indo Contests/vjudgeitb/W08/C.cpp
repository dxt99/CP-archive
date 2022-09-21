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
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll w[maxN];
vl adj[maxN];

void solve(){
	ll n,m; cin>>n>>m;
	for(int i=0;i<m;i++){
		ll x,y; cin>>x>>y;
		adj[x].pb(y);
		w[y]++;
	}
	vl ans;
	priority_queue <ll, vector<ll>, greater<ll>>pq;
	for(ll i=1;i<=n;i++){
		if(w[i])continue;
		pq.push(i);
	}
	while(!pq.empty()){
		ll idx=pq.top(); pq.pop();
		ans.pb(idx);
		for(auto v: adj[idx]){
			w[v]--;
			if(!w[v])pq.push(v);
		}
	}
	if(ans.size()==n){
		for(auto u:ans)cout<<u<<" ";
		cout<<endl;
	}else{
		cout<<"Sandro fails."<<endl;
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

