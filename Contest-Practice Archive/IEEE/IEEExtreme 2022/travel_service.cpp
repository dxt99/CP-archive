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
typedef priority_queue <pl, vector<pl>, greater<pl>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	ll n, cap, c;
	cin>>n>>cap>>c;
	vll arr;
	ll pre[n+2];
	pre[0]=0;
	for(int i=0; i<n; i++){
		ll x, val; cin>>x>>val;
		pre[i+1] = x + pre[i];
		arr.pb(mp(x,val));
	}
	arr.pb(mp(0,0));
	pre[n+1]=pre[n];
	ll dp[n+2];
	dp[0]=cap*c;
	for(int i=1; i<=n+1; i++){
		dp[i] = dp[i-1] + 500 + arr[i-1].sd * (arr[i-1].fs);
		for(int j=i-2; j>=0; j--){
			if(pre[i]-pre[j]>cap)break;
			dp[i] = min(dp[i], dp[j]+500+arr[i-1].sd*(pre[i]-pre[j]));
		}
	}
	cout<<dp[n+1]-500<<endl;
	
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
