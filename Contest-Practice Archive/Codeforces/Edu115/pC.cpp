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
	ll n; cin>>n;
	vl arr(n);
	ll sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	sum*=2;
	if(sum%n!=0){
		cout<<0<<endl;
		return;
	}
	sum/=n;
	sort(arr.begin(),arr.end());
	ll ans=0;
	for(int i=0;i<n;i++){
		ll l=lower_bound(arr.begin(),arr.end(),sum-arr[i])-arr.begin();
		ll r=upper_bound(arr.begin(),arr.end(),sum-arr[i])-arr.begin();
		if(arr[l]==sum-arr[i])ans+=r-l;
		if(arr[r]==sum-arr[i]&&r!=i)ans+=1;
		if(i>=l&&i<r)ans--;
	}
	ans/=2;
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
