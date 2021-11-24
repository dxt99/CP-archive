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

vl adj[maxN];
ll ans=Mod;
ll price[maxN];

void solve(){
	int n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>price[i];
	for(int i=0;i<m;i++){
		int x,y; cin>>x>>y;
		adj[--x].pb(--y);
		adj[y].pb(x);
	}
	for(int i=0;i<n;i++){
		for(auto v: adj[i]){
			for(auto y:adj[v]){
				for(auto z:adj[y])if(z==i)ans=min(ans,price[i]+price[v]+price[y]);
			}
		}
	}
	if(ans==Mod)cout<<-1<<endl;
	else cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	t=1;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
