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
	ll n,m; cin>>n>>m;
	vll box; // -1*val,quantity
	for(int i=0;i<m;i++){
		ll b, val;
		cin>>b>>val;
		box.pb(mp(-1*val,b));
	}
	sort(box.begin(),box.end());
	ll ans=0;
	for(auto i:box){
		if(i.sd>=n){
			ans-=(n*i.fs);
			break;
		}else{
			ans-=(i.fs*i.sd);
			n-=i.sd;
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

