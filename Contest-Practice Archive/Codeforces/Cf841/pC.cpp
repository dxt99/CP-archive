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
const int maxN=2e3+3;

void solve(){
	ll n; cin>>n;
	vl m(4*n, 0);
	
	vl arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	ll ans = 0;
	ll cur = 0;
	m[0]=1;
	for(int i=0; i<n; i++){
		ans += (i+1);
		cur ^= arr[i];
		for(int j=0; j*j<=2*n; j++){
			ll temp = cur^(j*j);
			ans -= m[temp];
		}
		m[cur]++;
	}
	cout<<ans<<endl;
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
