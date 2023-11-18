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
	int n, m; cin>>n>>m;
	int s = n + m;
	minh q;
	ll ans=0;
	vl a, b;
	for(int i=0; i<s; i++){
		int x; cin>>x;
		a.pb(x);
	}
	for(int i=0; i<s; i++){
		int x; cin>>x;
		b.pb(x);
	}
	for(int i=0; i<s; i++){
		ans += a[i];
		q.push(b[i]-a[i]);
	}
	for(int i=0; i<m; i++){
		ans += q.top();
		q.pop();
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
