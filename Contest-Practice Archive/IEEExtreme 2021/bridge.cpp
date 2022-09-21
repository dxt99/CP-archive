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

ll n,m;
vl adj1[maxN], adj2[maxN];
ll last1,last2;
bool vst1[maxN],vst2[maxN];
vl ans1,ans2;

bool dfs1(ll u,ll p,ll t){
	bool f=0;
	if(u==t)f=1;
	else for(auto v: adj1[u]){
		if(v==p)continue;
		f=dfs1(v,u,t);
		if(f)break;
	}
	if(f)ans1.pb(u);
	return f;
}

bool dfs2(ll u,ll p,ll t){
	bool f=0;
	if(u==t)f=1;
	else for(auto v: adj2[u]){
		if(f)break;
		if(v==p)continue;
		f=dfs2(v,u,t);
	}
	if(f)ans2.pb(u);
	return f;
}

void solve(){
	ans1.clear();
	ans2.clear();
	cin>>n;
	for(int i=0;i<n;i++){
		adj1[i].clear();
		vst1[i]=0;
	}
	for(int i=0;i<n-1;i++){
		ll x,y; cin>>x>>y; x--; y--;
		adj1[x].pb(y);
		adj1[y].pb(x);
	}
	cin>>m;
	for(int i=0;i<m;i++){
		adj2[i].clear();
		vst2[i]=0;
	}
	for(int i=0;i<m-1;i++){
		ll x,y; cin>>x>>y; x--; y--;
		adj2[x].pb(y);
		adj2[y].pb(x);
	}
	
	//diameter 1
	queue<ll> q1;
	ll u=0;
	vst1[u]=1;
	q1.push(u);
	while(!q1.empty()){
		u=q1.front();
		q1.pop();
		for(auto i:adj1[u]){
			if(vst1[i])continue;
			q1.push(i);
			vst1[i]=1;
			last1=i;
		}
	}
	// reset
	for(int i=0;i<n;i++)vst1[i]=0;
	u=last1;
	vst1[u]=1;
	q1.push(u);
	while(!q1.empty()){
		u=q1.front();
		q1.pop();
		for(auto i:adj1[u]){
			if(vst1[i])continue;
			q1.push(i);
			vst1[i]=1;
			last2=i;
		}
	}
	// path: last1-last2
	dfs1(last1,-1,last2);
	
	// repeat
	//diameter 2
	queue<ll> q2;
	u=0;
	vst2[u]=1;
	q2.push(u);
	while(!q2.empty()){
		u=q2.front();
		q2.pop();
		for(auto i:adj2[u]){
			if(vst2[i])continue;
			q2.push(i);
			vst2[i]=1;
			last1=i;
		}
	}
	// reset
	for(int i=0;i<m;i++)vst2[i]=0;
	u=last1;
	vst2[u]=1;
	q2.push(u);
	while(!q2.empty()){
		u=q2.front();
		q2.pop();
		for(auto i:adj2[u]){
			if(vst2[i])continue;
			q2.push(i);
			vst2[i]=1;
			last2=i;
		}
	}
	// path: last1-last2
	dfs2(last1,-1,last2);
	/*
	for(auto i: ans1)cout<<i<<".";
	cout<<endl;
	for(auto i: ans2)cout<<i<<".";
	cout<<endl;
	*/
	ll ret=ans1.size()/2+ans2.size()/2+1;
	ret=max(ret,ans1.size()-1);
	ret=max(ret,ans2.size()-1);
	cout<<ret<<endl;
	cout<<ans1[ans1.size()/2]+1<<" "<<ans2[ans2.size()/2]+1<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

