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
const ll big=1e15;
const ll low=1e5;
const ll two=31622777;
const int maxN=1e3+3;

ll calc(ll a, ll b, ll c, ll d, ll x){
	/*
	if(x*x<0 && (a||b)) return big+1;
	if(x*x*x<0 && a) return big+1;
	if(x*x*x*a<0) return big+1;
	*/
	ll ret = x*x*x*a + x*x*b + x*c + d;
	if(ret<0) return big+100;
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
	ll a,b,c,d; cin>>a>>b>>c>>d;
	ll f; cin>>f;
	cout<<binser((ll)0, big, a, b, c, d, f)<<endl;
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
