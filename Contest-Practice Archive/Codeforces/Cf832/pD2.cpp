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
	ll arr[n+1]; arr[0]=0;
	ll xr[n+1]; xr[0]=0;
	ll sum[n+1]; sum[0]=0;
	vl shrt(n+1, Mod);
	vll pev;
	vll pod;
	for(int i=0; i<=n; i++)shrt[i]=Mod;
	for(int i=1; i<=n; i++)cin>>arr[i];
	for(int i=1; i<=n; i++){
		xr[i]=arr[i]^xr[i-1];
		if(i%2)pod.pb(mp(xr[i],(ll)i));
		else pev.pb(mp(xr[i],(ll)i));
	}
	sort(pod.begin(),pod.end());
	sort(pev.begin(),pev.end());
	for(int i=0; i<=n; i++){
		vll& p = pod;
		if(i%2)p = pev;
		ll pos = lower_bound(p.begin(), p.end(), mp(xr[i], (ll)i)) - p.begin();
		if(pos>=p.size())continue;
		pl pr = p[pos];
		if(pr.fs!=xr[i])continue;
		if(pr.sd < i+1)continue;
		shrt[i+1]=pr.sd;
	}
	for(int i=1; i<=n; i++)sum[i]=arr[i]+sum[i-1];
	while(q--){
		ll l, r;
		cin>>l>>r;
		// xorsum !=0
		if(xr[r]^xr[l-1]){
			cout<<"-1"<<endl;
			continue;
		}
		// all zero
		if(sum[r]-sum[l-1]==0){
			cout<<"0"<<endl;
			continue;
		}
		// length is odd
		if((r-l)%2==0){
			cout<<"1"<<endl;
			continue;
		}
		// length is even
		// 1. prefix zero = 1
		// 2. else if no prefix xor is zero = -1
		// 3. else = 2
		if(arr[l]==0||arr[r]==0){
			cout<<"1"<<endl;
			continue;
		}
		
		if(shrt[l]>r){
			cout<<"-1"<<endl;
			continue;
		}
		cout<<"2"<<endl;
		
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
