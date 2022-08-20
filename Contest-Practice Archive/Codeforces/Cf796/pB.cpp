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

ll div2(ll k){
	int cnt = 0;
	while(k%2==0){
		cnt++;
		k/=2;
	}
	return cnt;
}

void solve(){
	ll n; cin>>n;
	ll eve = 0;
	ll maxi = Mod;
	for(int i=0; i<n; i++){
		ll x; cin>>x;
		if(x%2==0){
			eve++;
			maxi = min(maxi,div2(x));
		}
	}
	if(eve == n){
		cout<<eve+maxi-1<<endl;
	}else{
		cout<<eve<<endl;
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
