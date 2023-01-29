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

const ll upper = 1e15;

ll calc(ll a, ll b, ll c, ll d, ll x){
	ll ret = a;
	ret *= x;
	if(ret<0)return upper+3;
	ret *= x;
	if(ret<0)return upper+3;
	ret*=x;
	if(ret<0)return upper+3;
	b*=x;
	if(b<0)return upper+3;
	b*=x;
	if(b<0)return upper+3;
	ret+=b;
	if(ret<0)return upper+3;
	ret+=c*x;
	if(ret<0)return upper+3;
	ret+=d;
	if(ret<0)return upper+3;
	return ret;
}

ll binser(ll l, ll r, ll a, ll b, ll c, ll d, ll val){
	ll mid = (l+r)/2;
	ll f = calc(a,b,c,d,mid);
	if(f>val)r = mid-1;
	if(f<val)l = mid+1;
	if(f==val)return mid;
	return binser(l, r, a, b, c, d, val);
}

void solve(){
	ll a, b, c, d, tar;
	cin>>a>>b>>c>>d>>tar;
	ll x = binser((ll)0, upper, a, b, c ,d , tar);
	cout<<x<<endl;
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
