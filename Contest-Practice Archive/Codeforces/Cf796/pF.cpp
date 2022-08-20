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

void solve(){
	ll n,m; cin>>n>>m;
	ll a[n], b[n];
	vl segs[n+3];
	vl stops;
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=1; i<n; i++)a[i]+=a[i-1];
	for(int i=0; i<n; i++)cin>>b[i];
	for(int i=1; i<n; i++)b[i]+=b[i-1];
	for(int i=0; i<m; i++){
		ll l,r; cin>>l>>r;
		segs[l].pb(r);
	}
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
