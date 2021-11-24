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

set<ll> root;
bool visit[N];

void solve(){
	memset(visit,0,sizeof(visit));
	int n;
	cin>>n;
	vl adj[n];
	int deg[n];
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		deg[i]=x;
		if(x==0)root.insert(i);
		for(int it=0;it<x;it++){
			int k; 
			cin>>k;
			adj[--k].pb(i);
			//cout<<k<<","<<i<<"//";
		}
	}
	stack<ll> temp;
	ll ans=0;
	while(true){
		if(root.empty())break;
		ans++;
		while(!root.empty()){
			ll u=*root.begin();
			root.erase(u);
			//cout<<u<<"-";
			visit[u]=1;
			for(auto v:adj[u]){
				//cout<<v<<"+";
				deg[v]--;
				if(deg[v]==0&&u<v)root.insert(v);
				else if(deg[v]==0)temp.push(v);
			}
		}
		while(!temp.empty()){
			root.insert(temp.top());
			//cout<<temp.top()<<"..";
			temp.pop();
		}
	}
	for(int i=0;i<n;i++)if(!visit[i])ans=-1;
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
