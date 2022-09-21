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
	bool f=0;
	ll a=0;
	ll b=0;
	ll d1=0;
	ll d2=0;
	for(int i=0;i<n;i++){
		ll x,y; cin>>x>>y;
		a+=x; b+=y;
		if(f)swap(x,y);
		d1+=x;
		d2+=y;
		if(a!=b)f^=1;
	}
	
	if(d2>d1)cout<<2<<endl;
	else cout<<1<<endl;
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

