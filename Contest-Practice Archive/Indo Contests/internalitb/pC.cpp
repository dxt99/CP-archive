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

ll arr[maxN][maxN];
bool vis[maxN][maxN];

ll f(ll i, ll j){
	if(vis[i][j])return 0;
	vis[i][j]=1;
	if(arr[i][j]==0)return 0;
	ll ret = 1;
	for(int a=-1; a<2; a++){
		for(int b=-1; b<2; b++){
			if(a==0 && b==0)continue;
			ret += f(i+a, j+b);
		}
	}
	return ret;
}

void solve(){
	for(int i=0; i<maxN; i++){
		for(int j=0; j<maxN; j++)arr[i][j]=0;
	}
	ll n, m; cin>>n>>m;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			cin>>arr[i][j];
		}
	}
	ll ans = 0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(vis[i][j])continue;
			ll t = f(i, j);
			ans = max(ans, t);
		}
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
