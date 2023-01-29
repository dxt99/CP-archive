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

const int N = 3e5 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

ll sum[N];
ll sq[N];
ll val[N];

void preprocess(){
	sum[0]=0; sq[0]=0; val[0]=0;
	for(ll i=1; i<N; i++){
		sum[i]=sum[i-1]+i;
		sq[i]=sq[i-1]+i*i;
		val[i]=i*sum[i]-sq[i];
	}
}

void solve(){
	ll n,q; cin>>n>>q;
	set<ll> s;
	s.insert(0);
	s.insert(n+1);
	ll ans = val[n+1];
	while(q--){
		ll k; cin>>k;
		auto it = s.find(k);
		if(it == s.end()){
			// insert new node;
			s.insert(k);
			it = s.find(k);
			auto it_copy = it;
			ll bef = *(--it_copy);
			ll nx = *(++it);
			ans = ans - val[nx-bef] + val[k-bef] + val[nx-k];
		}else{
			// erase node
			auto it_copy = it;
			ll bef = *(--it_copy);
			ll nx = *(++it);
			ans = ans + val[nx-bef] - val[k-bef] - val[nx-k];
			s.erase(k);
		}
		cout<<ans<<endl;
	}
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
