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
	ll n, q; cin>>n>>q;
	ll ans=3;
	if(n==1)ans=1;
	else if(n==2)ans=3;
	else{
		n-=2;
		ll l = 3;
		ll r = 3 + (n-1)/2;
		ans+=( (l+r)*n )/2;
	}
	cout<<ans<<endl;
	for(int i=0; i<q; i++){
		ll x; cin>>x;
		if(x==1)cout<<1<<endl;
		else if(x==2)cout<<2<<endl;
		else{
			ll k = (3+(x-3)/2);
			cout<<k<<endl;
		}
	}
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
