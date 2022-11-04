#include<bits/stdc++.h>
#define pb push_back
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
const int maxN=2e3+3;

int arr[maxN][maxN];
bool v[maxN][maxN];


struct info{
	int x, y;
	int lmax, rmax;
};
void solve(){
	ll n,m; cin>>n>>m;
	ll r,c; cin>>r>>c;
	ll lmax, rmax; cin>>lmax>>rmax;
	
	for(int i=1; i<=n; i++){
		string s; cin>>s;
		for(int j=1; j<=m; j++){
			if(s[j-1]=='.')arr[i][j]=1;
		}
	}
	queue<info> q;
	info i  = {r,c,lmax,rmax};
	q.push(i);
	while(!q.empty()){
		info i = q.front();
		q.pop();
		// walls
		if (arr[i.x][i.y]==0)continue;
		
		v[i.x][i.y]=1;
		//up down
		if(!v[i.x-1][i.y])q.push({i.x-1, i.y, i.lmax, i.rmax});
		if(!v[i.x+1][i.y])q.push({i.x+1, i.y, i.lmax, i.rmax});
		
		//left right
		if(i.lmax>=1 && !v[i.x][i.y-1])q.push({i.x, i.y-1, i.lmax-1, i.rmax});
		if(i.rmax>=1 && !v[i.x][i.y+1])q.push({i.x, i.y+1, i.lmax, i.rmax-1});
	}
	ll ans=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			ans+=v[i][j];
		}
	}
	cout<<ans<<endl;
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
