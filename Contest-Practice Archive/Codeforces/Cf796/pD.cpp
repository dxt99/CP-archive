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

ll lsum(ll a, ll b){
	ll tot = a+b;
	ll cnt = b-a+1;
	if(tot%2 ==0) tot/=2;
	else cnt/=2;
	return tot*cnt;
}

void solve(){
	ll n; cin>>n;
	ll k; cin>>k;
	ll arr[n];
	ll sum = 0;
	ll ans = 0;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		sum += arr[i];
	}
	if(n==1){
		ans = arr[0]+k-1;
	}
	else if(k==n){
		ans = sum;
		ll temp = lsum(1,n-1);
		ans += temp;
	}
	else if(k>n){
		ans = sum;
		ll time = (k-n+2);
		ans += n*(k-1);
		ll temp = lsum(1,n-1);
		ans-=temp;
	}else{
		for(int i=1;i<n;i++){
			arr[i]+=arr[i-1];
		}
		ll maxi = k;
		for(int i=k;i<n;i++){
			if(arr[i]-arr[i-k]>arr[maxi]-arr[maxi-k]){
				maxi = i;
			}
		}
		ans = arr[maxi]-arr[maxi-k];
		if(arr[k-1]>ans) ans = arr[k-1];
		ll temp = lsum(1, k-1);
		ans+=temp;
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
