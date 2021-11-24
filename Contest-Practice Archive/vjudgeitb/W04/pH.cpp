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

ll n,m; //stall-cows
ll arr[maxN];

ll count(ll s){
	ll cur=0;
	ll ret=0;
	for(int i=0;i<n;i++){
		if(cur<=arr[i]){
			cur=arr[i]+s;
			ret++;
		}
	}
	return ret;
}

ll binser(ll l,ll r){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	ll val=count(mid);
	//cout<<val<<".";
	if(val<m) return binser(l,mid-1);
	if(val>=m) return binser(mid+1,r);
}

void solve(){
	cin>>n>>m;
	for(int i=0;i<n;i++)cin>>arr[i];
	sort(arr,arr+n);
	ll r=arr[n-1]-arr[0];
	ll ans=binser(0,r);
	if(count(ans)<m)ans--;
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
