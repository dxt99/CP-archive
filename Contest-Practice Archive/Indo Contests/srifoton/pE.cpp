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

void solve(){
	ll n; cin>>n;
	ll x=0;
	ll y=0;
	ll ans=1;
	for(int i=0;i<n;i++){
		ll a,b; cin>>a>>b;
		while(x<a&&y<b){
			if(x>y)y++;
			else x++;
			if(x==y)ans++;
		}
		while(x<a){
			x++;
			if(x==y)ans++;
		}
		while(y<b){
			y++;
			if(x==y)ans++;
		}
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

