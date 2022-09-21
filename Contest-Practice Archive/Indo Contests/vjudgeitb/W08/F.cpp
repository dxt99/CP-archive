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

vl cst[maxN];

void solve(){
	int n; cin>>n;
	int temp; for(int i=0;i<n;i++)cin>>temp;
	int m; cin>>m;
	for(int i=0;i<m;i++){
		ll x,y,w;
		cin>>x>>y>>w;
		cst[y].pb(w);
	}
	ll ans=0;
	bool f=0;
	for(int i=1;i<=n;i++){
		if(cst[i].size()==0&&!f){
			f=1;
			continue;
		}
		if(cst[i].size()==0&&f){
			cout<<-1<<endl;
			return;
		}
		ll mini=cst[i][0];
		for(auto j:cst[i])mini=min(mini,j);
		ans+=mini;
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

