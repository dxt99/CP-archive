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

ll gcd(ll a,ll b){
	if(a>b)swap(a,b);
	if(a==0)return b;
	return gcd(b%a,a);
}

void solve(){
	ll n; cin>>n;
	ll arr[n];
	for(int i=0;i<n;i++)cin>>arr[i];
	for(int i=0;i<n-1;i++)arr[i]=abs(arr[i+1]-arr[i]);
	ll ans=0;
	n--;
	sort(arr,arr+n);
	for(int i=0;i<n;i++){
		ll tmp=0;
		for(int j=i;j<i+n/2&&j<n;j++){
			tmp=gcd(tmp,arr[j]);
		}
		if(tmp==0){
			ans=0;
			break;
		}
		ans=max(ans,tmp);
	}
	if(ans==0)ans=-1;
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

