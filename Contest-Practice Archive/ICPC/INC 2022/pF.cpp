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

const ll N = 1e12 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	ll n, s, x; cin>>n>>s>>x;
	ll arr[n+1]; arr[0]=0;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		arr[i]+=arr[i-1];
	}
	ll tot = abs(arr[n]);
	ll ans = N;
	for(int i=0; i<=n; i++){
		ll tmp = s - x + arr[i];
		if(tmp<0) continue;
		tmp %= tot;
		ans = min(ans, tmp);
		//cout<<tmp<<endl;
	}
	if(ans==N){
		cout<<-1<<endl;
	}
	else cout<<ans+x<<endl;
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
