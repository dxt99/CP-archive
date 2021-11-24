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

map<ll,ll> hsh;

void solve(){
	vl ans;
	ll n; cin>>n;
	for(int i=1;i<=500;i++)hsh[i]=Mod;
	hsh[0]=-1;
	ll arr[n];
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		hsh[x]=min((ll)i,hsh[x]);
		arr[i]=x;
	}
	ans.pb(0);
	for(int i=1;i<=500;i++){
		ll tar=hsh[i];
		for(int j=i-1;j>0;j--){
			ll l=hsh[i^j];
			ll r=hsh[j];
			if(l==Mod||r==Mod)continue;
			else if(arr[j]>arr[(i^j)]&&l>r){
				tar=min(tar,max(l,r));
			}else if(arr[j]<arr[(i^j)]&&l<r){
				tar=min(tar,max(l,r));
			}
		}
		hsh[i]=tar;
		if(tar!=Mod)ans.pb(i);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
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

