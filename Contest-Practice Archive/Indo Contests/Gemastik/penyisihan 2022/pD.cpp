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

map<ll, ll> cnt;

void solve(){
	ll n; cin>>n;
	set<ll> nums;
	for(int i=0; i<n; i++){
		int x; cin>>x; nums.insert(x);
		cnt[x]++;
	}
	vl arr;
	for(auto n: nums){
		arr.pb(cnt[n]);
	}
	sort(arr.begin(), arr.end());
	vl sum;
	sum.pb(arr[0]);
	ll sz = arr.size();
	for(int i=1; i<sz; i++){
		sum.pb(arr[i]);
		sum[i]+=sum[i-1];
	}
	for(int i=1; i<=n; i++){
		ll up= std::upper_bound (arr.begin(), arr.end(), i-1) - arr.begin();
		if(up==0){
			cout<<"0 "; continue;
		}
		ll sig = sum[up-1];
		//cout<<sig<<"-"<<up-1<<endl;
		if(sig<i){
			ll ans = sig;
			if(sum[sz-1]>=2*i)ans=min(sig, i-sig);
			cout<<ans<<" "; continue;
		}
		ll ig = sig/i;
		ll temp = sum[up-1]-sum[up-1-ig];
		cout<<sig-temp<<" "; continue;
	}
	cout<<endl;
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
