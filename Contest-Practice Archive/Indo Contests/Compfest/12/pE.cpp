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

void solve(){
	int n,k; cin>>n>>k;
	vl a(n);
	vl b(n);
	for(int i=0; i<n; i++)cin>>a[i];
	for(int i=0; i<n; i++)cin>>b[i];
	ll sum=0;
	ll mini=b[0];
	for(int i=0; i<n; i++)sum+=a[i];
	for(int i=0; i<n-1; i++)mini=min(b[i],mini);
	if(k>=2){
		cout<<max(sum-mini, a[n-1]-b[n-1])<<endl;
		return;
	}
	// case 1: take a[n-1], starting at first profit
	ll ans=-1;
	for(int i=1; i<n; i++){
		a[i]+=a[i-1];
	}
	for(int i=0; i<n; i++){
		int cost = 0;
		if(i>0)cost=a[i-1];
		ans = max(ans, sum-cost-b[i]);
	}
	// case 2: take all a[0 ~ n-2]
	sum=a[n-2];
	ans = max(ans, sum-mini);
	cout<<ans<<endl;
}
 
int main(){
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
