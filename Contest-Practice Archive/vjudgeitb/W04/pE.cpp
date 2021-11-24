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
const int maxN=1e5+3;

ll chk(ll n,ll base){
	ll ret=0;
	while(n%base==0){
		ret++;
		n/=base;
	}
	return ret;
}

void solve(){
	ll n; cin>>n;
	vector<pair<pl,ll>> expo; // <-3,2>,num
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		expo.pb(mp(mp(-1*chk(x,3),chk(x,2)),x));
	}
	sort(expo.begin(),expo.end());
	for(int i=0;i<n;i++)cout<<expo[i].sd<<" ";
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
