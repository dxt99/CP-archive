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

const int N = 4e3 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	ll n; cin>>n;
	ll arr[n];
	map<ll, ll> hsh;
	set<ll> nums;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		nums.insert(arr[i]);
		hsh[arr[i]]++;
	}
	ll ans = 0;
	for(auto num: nums){
		ll cnt = hsh[num];
		ans = ans + (cnt) * (cnt-1) * (cnt-2);
		for(ll p=2; p<N; p++){
			if(p*p > num) break;
			ll cur = p;
			if(num%(cur*cur)==0){
				ans = ans + hsh[num] * (hsh[num/cur]) * (hsh[num/(cur*cur)]);
			}
		}
	}
	cout<<ans<<endl;
	return;
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
