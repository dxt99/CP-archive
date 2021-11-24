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
const int maxN=1e3+3;

pl arr[maxN][maxN]; //left/up
ll n,m;

pl count(ll i,ll j){
	if(i==n-1&&j==m-1)return arr[i][j]=mp(1,1);
	if(arr[i][j].fs!=-1)return arr[i][j];
	arr[i][j]=mp(1,1);
	if(i<n-1)arr[i][j].sd+=count(i+1,j).fs;
	if(j<m-1)arr[i][j].fs+=count(i,j+1).sd;
	return arr[i][j];
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)arr[i][j]=mp(-1,-1);
	}
	count(0,0);
	bool state[n][m];
	ll ans=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			ans+=arr[i][j].fs;
			ans+=arr[i][j].sd;
			ans-=1;
			state[i][j]=1;
		}
	}
	ll q; cin>>q;
	for(int i=0;i<q;i++){
		ll x,y;
		cin>>x>>y;
		x--; y--;
		state[x][y]^=1;
		if(state[x][y]){
			
		}
		else{
			ans-=(arr[x][y].fs+arr[x][y].sd-1);
		}
		cout<<ans<<"\n";
	}
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
