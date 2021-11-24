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
typedef priority_queue <pl, vector<pl>, greater<pl>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

ll w[maxN];
vl adj[maxN];

void solve(){
	int n,m; cin>>n>>m;
	for(int i=0;i<n;i++){
		w[i]=0;
		adj[i].clear();
	}
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		adj[y].pb(x);
		w[x]++;
	}
	minh pq;
	vll ans;
	for(int i=0;i<n;i++)if(!w[i]){
		pq.push(mp(0,i));
	}
	while(!pq.empty()){
		pl cur=pq.top();pq.pop();
		ans.pb(mp(cur.fs+1,cur.sd));
		for(auto i: adj[cur.sd]){
			w[i]--;
			if(!w[i])pq.push(mp(cur.fs+1,i));
		}
	}
	//sort(ans.begin(),ans.end());
	for(auto p:ans){
		printf("%d %d\n",p.fs,p.sd);
	}
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
 		printf("Scenario #%d: \n",i+1);
		solve();
	}
}

