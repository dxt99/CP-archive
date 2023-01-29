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

ll gc[N];

void preprocess(ll n){
	for(int i=0; i<=n+4; i++){
		gc[i]=0;
	}
	for(int i=n; i>=2; i--){
		gc[i] = n/i;
		gc[i] = (gc[i]*(gc[i]-1))/2;
		for(int j=2*i; j<=n; j+=i){
			gc[i]-=gc[j];	
		}
	}
	/*
	for(int i=0; i<=n; i++){
		cout<<"gc["<<i<<"] = "<<gc[i]<<endl;
	}
	*/
}

void solve(){
	ll n, m; cin>>n>>m;
	preprocess(n);
	ll cur = min(n, m);
	ll ans = 0;
	while(m>0 && cur>0){
		cur = min(cur, m);
		ll cnt = gc[cur+1]; // num of pairs w/ gcd = cur+1
		cnt = min(cnt, m);
		// w = cur + 1 = k, place cur at a time
		if(cur>1)cnt = cnt - (cnt % (cur));
		ll t = (cnt)/(cur);
		ans += t * (cur+1);
		m -= cnt; 
		cur--;
	}
	if(m!=0)cout<<-1<<endl;
	else cout<<ans<<endl;
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
