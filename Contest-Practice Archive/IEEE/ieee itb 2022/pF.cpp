#include<bits/stdc++.h>
#define pb push_back
#define mpair make_pair
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

vl primes;
bool f[N];

void preprocess(){
	for(int i=2; i<N; i++){
		if(f[i])continue;
		primes.pb(i);
		for(int j=i*i; j<N; j+=i)f[i]=1;
	}
}

map<ll, ll> mp;

void solve(){
	ll n, m; cin>>n>>m;
	vl a(n);
}
 
int main(){
	preprocess();
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
