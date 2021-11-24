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

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

void solve(){
	ll n,m; cin>>n>>m;
	ll arr[m];
	for(int i=0;i<m;i++)cin>>arr[i];
	sort(arr,arr+m);
	reverse(arr,arr+m);
	ll ans=0;
	ll tmp=0;
	for(int i=0;i<m;i++){
		tmp+=n-arr[i];
		if(tmp>=n)break;
		else ans++;
	}
	cout<<ans<<endl;
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

