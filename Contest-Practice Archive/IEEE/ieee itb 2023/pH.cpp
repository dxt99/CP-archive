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

vl val(N);
vl adj[N];

int ans = 0;
void color(int u, int par, bool inv=false){
    if (inv) val[u] *= -1; 
    for(auto v: adj[u]){
        if (v == par)continue;
        color(v, u, !inv);
    }
}


void solve(){
	ll n; cin>>n;
    for (int i=0; i<n; i++) cin>>val[i];
    for (int i=0; i<n-1; i++){
        int x,y;
        cin>>x>>y;
        x--; y--;
        adj[x].pb(y);
        adj[y].pb(x);
    }
    color();
    // find all paths in tree, sum = 0 (LCA?)
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
