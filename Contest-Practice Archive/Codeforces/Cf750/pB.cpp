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
	ll cnt0=0;
	ll cnt1=0;
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		if(x==0)cnt0++;
		if(x==1)cnt1++;
	}
	ll ans=1;
	if(cnt1==0)cout<<0<<endl;
	else{
		while(cnt0--)ans<<=1;
		ans*=(cnt1);
		cout<<ans<<endl;
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

