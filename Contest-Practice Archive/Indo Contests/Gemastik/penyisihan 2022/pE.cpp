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

ll a, b;
ll dist(ll x, ll y){
	ll dx=abs(x-a);
	ll dy=abs(y-b);
	return dx*dx + dy*dy;
}

void solve(){
	cin>>a>>b;
	ll n; cin>>n;
	vl arr;
	for(int i=0; i<n; i++){
		ll x, y; cin>>x>>y;
		arr.pb(dist(x,y));
	}
	sort(arr.begin(),arr.end());
	ll q; cin>>q;
	for(int i=0; i<q; i++){
		ll r; cin>>r;
		r*=r;
		ll ans = std::upper_bound (arr.begin(), arr.end(), r) - arr.begin();
		cout<<ans<<endl;
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
