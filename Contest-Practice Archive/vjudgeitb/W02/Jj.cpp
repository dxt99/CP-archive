#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e9+1;

vl lucky;
vl dp[10];

void preprocess(){
	ll k=10;
	dp[0].pb(4);
	dp[0].pb(7);
	lucky.pb(4);
	lucky.pb(7);
	int i=0;
	while(k<maxN){ //lucky auto sorted, O(log(n))
		for(auto x:dp[i]){
			dp[i+1].pb(4*k+x);
			lucky.pb(4*k+x);
		}
		for(auto x:dp[i]){
			dp[i+1].pb(7*k+x);
			lucky.pb(7*k+x);
		}
		k*=10;
		i++;
	}
}

ll binser(ll l,ll r,ll val){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	//printf(".%d",mid);
	if(lucky[mid]==val)return mid;
	if(lucky[mid]>val&&lucky[mid-1]<val)return mid;
	if(lucky[mid]>val) return binser(l,mid-1,val);
	if(lucky[mid]<val) return binser(mid+1,r,val);
}

void solve(){
	ll l,r;
	cin>>l>>r;
	ll x=binser(0,lucky.size()-1,l);
	ll y=binser(0,lucky.size()-1,r);
	//cout<<x<<"--"<<y<<endl;
	if(l==r){
		cout<<lucky[x]<<endl;
		return;
	}
	if(x==y){
		cout<<lucky[x]*(r-l+1)<<endl;
		return;
	}
	ll ans=(lucky[x]-l+1)*lucky[x];
	ans+=(r-lucky[y-1])*lucky[y];
	for(int i=x;i<y-1;i++){
		ans+=(lucky[i+1]-lucky[i])*lucky[i+1];
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	preprocess();
	//for(auto i:lucky)cout<<i<<endl;
	
	int t;
	t=1;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
