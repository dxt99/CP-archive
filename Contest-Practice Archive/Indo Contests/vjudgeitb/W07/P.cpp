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

vll adj[maxN];
priority_queue<pair<ll,pl>, vector<pair<ll,pl>>, greater<pair<ll,pl>>>pq;
priority_queue<pair<ll,pl>, vector<pair<ll,pl>>, greater<pair<ll,pl>>>temp;
set<pl> done;

ll limit=1e6;

void solve(){
	ll n,m,q; cin>>n>>m>>q;
	for(int i=0;i<m;i++){
		ll x,y,w; cin>>x>>y>>w;
		adj[x].pb(mp(w,y));
		adj[y].pb(mp(w,x));
		temp.push(mp(w,mp(x,y)));
	}
	for(int i=0;i<400&&!temp.empty();i++){
		auto s=temp.top(); temp.pop();
		pq.push(s);
	}
	for(int i=1;i<=n;i++)sort(adj[i].begin(),adj[i].end());
	for(int i=1;i<=n;i++)done.insert(mp(i,i));
	pair<ll,pl> cur;
	while(!pq.empty()&&q--){
		cur=pq.top(); pq.pop();
		while(done.count(mp(cur.sd.fs,cur.sd.sd))>0){
			cur=pq.top(); pq.pop();
		}
		done.insert(mp(cur.sd.fs,cur.sd.sd));
		done.insert(mp(cur.sd.sd,cur.sd.fs));
		for(auto i:adj[cur.sd.fs]){
			if(limit&&!done.count(mp(cur.sd.sd,i.sd))){
				pq.push(mp(cur.fs+i.fs,mp(cur.sd.sd,i.sd)));
				limit--;
			}
		}
		for(auto i:adj[cur.sd.sd]){
			if(limit&&!done.count(mp(cur.sd.fs,i.sd))){
				pq.push(mp(cur.fs+i.fs,mp(cur.sd.fs,i.sd)));
				limit--;
			}
		}
	}
	cout<<cur.fs<<endl;
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

