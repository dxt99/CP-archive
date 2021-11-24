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
const int maxN=1e5+3;

vl adj[maxN];
bool vis[maxN];
ll f,s;
vl ls;

ll dfs(ll node,ll dist){
	vis[node]=1;
	for(auto i:adj[node]){
		if(!vis[i])return dfs(i,dist+1);
	}
	return dist;
}

bool canwin(ll k){
	return (k<2)||((k-2)%3==0);
}

bool canlose(ll k){
	return ((k%3)==0);
}
void solve(){
	ll n; cin>>n;
	ll arr1[n];
	ll arr2[n];
	vl cycles;
	for(int i=0;i<n;i++){
		cin>>arr1[i];
	}
	for(int i=0;i<n;i++){
		cin>>arr2[i];
	}
	for(int i=0;i<n;i++)adj[arr1[i]].pb(arr2[i]);
	for(int i=1;i<=n;i++){
		ll l=0;
		if(!vis[i])l=dfs(i,1);
		if(l>0)cycles.pb(l);
		//if(l<2||(l-2)%3==0)f++;
		//else s++;
	}
	bool cur=1; //0 fs wins, 1 sd wins
	for(auto i: cycles){
		cout<<i<<endl;
		if(cur&&canwin(i))cur=0;
		else if(!cur&&!canlose(i))cur=1;
	}
	if(!cur)cout<<"First\n";
	else cout<<"Second\n";
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

