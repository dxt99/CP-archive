#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef pair<pair<ll,ll>, pair<ll, ll>> plll;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <plll> maxh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

vl arr(maxN);
vll edge;
vl primes;
maxh pq;
ll n, m;

bool isPrime(ll x){
	for(int i=2; i*i<=x; i++){
		if(x%i==0)return 0;
	}
	return 1;
}

void preprocess(){
	for(int i=2; i<maxN; i++){
		if(isPrime(i))primes.pb(i);
	}
}

ll gcd(ll a, ll b){
	if(a==0)return b;
	if(a>b)return gcd(b,a);
	return gcd(b%a, a);
}

ll cnt(ll x, ll prime){
	ll ret = 0;
	while(x%prime==0){
		x/=prime;
		ret++;
	}
	return ret;
}

bool make_pq(ll prime){
	bool ret=0;
	while(!pq.empty())pq.pop();
	for(auto e:edge){
		ll num = cnt(gcd(arr[e.fs],arr[e.sd]), prime);
		if(num>0)ret=1;
//		cout<<num<<" "<<max(e.fs,e.sd)<<endl;
		pq.push(mp(mp(num, abs(cnt(arr[e.fs], prime)-cnt(arr[e.sd],prime))), e));
	}
	return ret;
}

void proc(ll a, ll b, ll prime){
	ll c = prime;
	arr[a]/=c;
	arr[b]/=c;
}

ll run(ll prime){
	ll ans = 0;
	while(make_pq(prime)){
		auto p = pq.top();
		auto e = p.sd;
		proc(e.fs, e.sd, prime);
		ans++;
	}
	return ans;
}

void solve(){
	cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>arr[i];
	ll ans=0;
	for(int i=0; i<m; i++){
		ll x,y; cin>>x>>y;
		edge.pb(mp(x,y));
	}
	
	for(auto p: primes){
		ans+=run(p);
	}
//	for(int i=1; i<=n; i++)cout<<arr[i]<<" ";
//	cout<<endl;
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	preprocess();
	int t=1;
//	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
