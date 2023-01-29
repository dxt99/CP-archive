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

vlll arr;
vl dp(100005, 0); 
void solve(){
	ll n; cin>>n;
	for(int i=0; i<n; i++){
		ll p, l, v;
		cin>>p>>l>>v;
		arr.pb(mp(-1*p,mp(l,v)));
	}
	sort(arr.begin(), arr.end());
	set<ll> dpKey;
	for(auto t: arr){
		// process qs
		ll l = t.sd.fs;
		ll val = t.sd.sd;
		auto it = dpKey.upper_bound(l);
		if(it==dpKey.end()){
			dpKey.insert(l);
			dp[l] = max(dp[l], val);
		}
		else {
			dpKey.insert(l);
			dp[l] = max(dp[l], dp[*it]+val);
		}
	}
	ll ans = 0;
	for(auto q: dp){
		ans = max(ans, q);
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
