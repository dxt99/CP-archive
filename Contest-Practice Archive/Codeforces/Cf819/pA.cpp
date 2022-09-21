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
	int n; cin>>n;
	vl arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	ll maxi=0;
	ll mini=arr[1];
	ll dif = arr[n-1]-arr[0];
	for(int i=0; i<n; i++){
		if(i<n-1)maxi = max(maxi, arr[i]);
		if(i>0)mini = min(mini, arr[i]);
		if(i>0)dif = max(dif, (arr[i-1]-arr[i]));
	}
	ll ans = max(arr[n-1]-mini, maxi-arr[0]);
	ans = max(ans, dif);
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
