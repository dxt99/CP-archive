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

ll cnt[550];

void solve(){
	for(int i=0;i<550;i++)cnt[i]=Mod;
	ll n;
	cin>>n;
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		cnt[x]=min(x,cnt[x]);
		for(int j=1;j<=512;j++){
			if(cnt[j]<x)cnt[j^x]=min(cnt[j^x],x);
		}
	}
	vl ans;
	ans.pb(0);
	for(int i=1;i<550;i++){
		if(cnt[i]!=Mod){
			ans.pb(i);
		}
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

