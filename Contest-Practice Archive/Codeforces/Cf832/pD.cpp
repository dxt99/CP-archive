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
map<ll, int> xrev;
map<ll, int> xrod;

void solve(){
	ll n, q; cin>>n>>q;
	ll arr[n+1]; arr[0]=0;
	ll xr[n+1]; xr[0]=0;
	ll sum[n+1]; sum[0]=0;
	ll rd[n+1];
	ll shrt[n+1];
	for(int i=0; i<=n; i++)shrt[i]=-1;
	for(int i=1; i<=n; i++)cin>>arr[i];
	vll pts;
	for(int i=1; i<=n; i++){
		xr[i]=arr[i]^xr[i-1];
		if(i%2){
			if(xrev.count(xr[i])>0){
				shrt[i] = xrev[xr[i]];
			}
			xrod[xr[i]]=i;
		}else{
			if(xrod.count(xr[i])>0){
				shrt[i] = xrod[xr[i]];
			}
			xrev[xr[i]]=i;
		}
	}
	for(int i=0; i<=n; i++)rd[i]=-1;
	for(int i=1; i<=n; i++){
		ll val = shrt[i];
		if(val>n)continue;
		if(i> val) continue;
		rd[val] = i;
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
		
		if(shrt[r]<l){
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
