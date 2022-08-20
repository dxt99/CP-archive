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
	ll n; cin>>n;
	ll m = n;
	ll k = 1;
	ll ans = 0;
	ll zero = 0;
	ll one = 0;
	while(!(one)){
		if(n%2 == 1){
			one = 1;
			ans+=k;
			if((m^ans) !=0) zero = 1;
		}
		k*=2;
		n/=2;
	}
	n = m;
	k=1;
	while(!zero){
		if(n%2 == 0){
			zero = 1;
			ans+=k;
		}
		k*=2;
		n/=2;
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
