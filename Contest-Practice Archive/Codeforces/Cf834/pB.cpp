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

vl sums;
void precompute(){
	ll sum=0;
	for(int i=0; i<100; i++){
		sum+=i;
		sums.pb(sum);
	}
}

void solve(){
	ll n, s; cin>>n>>s;
	vl arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	sort(arr.begin(), arr.end());
	ll sum = arr[0];
	for(int i=1; i<n; i++){
		sum+=arr[i];
		if(arr[i]==arr[i-1]){
			cout<<"NO"<<endl;
			return;
		}
	}
	ll maxi=arr[n-1];
	for(int i=0; i<100; i++){
		if(s+sum==sums[i] && i>=maxi){
			cout<<"YES"<<endl;
			return;
		}
	}
	cout<<"NO"<<endl;
}
 
int main(){
	precompute();
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
