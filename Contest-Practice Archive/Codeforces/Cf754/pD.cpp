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
const int maxN=2e5+3;

vl adj[maxN];
int col[maxN];
int cnt[3];
bool done[maxN];

int xxor(int a){
	if(a==1)return 2;
	else return 1;
}

bool dfs(int u){
	for(auto v:adj[u]){
		if(col[v]==0){
			col[v]=xxor(col[u]);
			cnt[col[v]]++;
			if(!dfs(v))return 0;
		}
		else if(col[v]!=xxor(col[u])){
			return 0;
		}
	}
	return 1;
}

void solve(){
	cnt[1]=0; cnt[2]=0;
	int n; cin>>n;
	for(int i=0;i<=n;i++){
		adj[i].clear();
		col[i]=0;
		done[i]=0;
	}
	for(int i=0;i<n-1;i++){
		int x,y; cin>>x>>y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	col[1]=1;
	cnt[1]++;
	dfs(1);
	vl ans[3];
	int id=1;
	if(cnt[1]>cnt[2])id=2;
	int s=cnt[id];
	int i=1;
	while(s>0){
		if(s%2){
			for(int j=0;j<i;j++){
				ans[id].pb(j+i);
				done[i+j]=1;
			}
		}
		i*=2;
		s/=2;
	}
	for(int i=1;i<=n;i++)if(!done[i])ans[xxor(id)].pb(i);
	int l=0;
	int r=0;
	for(int i=1;i<=n;i++){
		if(col[i]==1){
			cout<<ans[1][l]<<" ";
			l++;
		}else{
			cout<<ans[2][r]<<" ";
			r++;
		}
	}
	cout<<endl;
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

