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

ll a,b; 

ll lg(ll n){
	ll ret=1;
	while(n>0){
		n/=10;
		ret*=10;
	}
	return ret;
}

ll f(ll z){
	if(lg(z)-1==z)return a;
	return 0;
}

void solve(){
	cin>>a>>b;
	ll ans=0;
	for(int i=2;i<b;i++)ans+=f(i);
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
