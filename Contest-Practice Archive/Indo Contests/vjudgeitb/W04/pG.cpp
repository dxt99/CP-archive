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
const int maxN=1e3+3;

ll n; ll arr[maxN];
vl l;
vl r;

void solve(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<n;k++){
				ll curl=arr[i]*arr[j]+arr[k];
				ll curr=arr[i]*(arr[j]+arr[k]);
				l.pb(curl);
				if(arr[i]!=0)r.pb(curr);
			}
		}
	}
	sort(r.begin(),r.end());
	ll ans=0;
	for(auto curr: l){
		ll lb=lower_bound(r.begin(),r.end(),curr)-r.begin();
		ll rb=upper_bound(r.begin(),r.end(),curr)-r.begin();
		ans+=(rb-lb);
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
