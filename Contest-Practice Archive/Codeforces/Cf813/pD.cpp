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
const ll mx = 1e9;

void solve(){
	ll n,k; cin>>n>>k;
	vl arr(n);
	vl ori(n);
	ll maxi = 0;
	ll mini = mx;
	for(int i=0; i<n; i++){
		cin>>arr[i];
		ori[i]=arr[i];
		if(arr[i]>maxi)maxi=arr[i];
		if(arr[i]<mini)mini=arr[i];
	}
	for(int i=0; i<5; i++)arr.pb(mx);
	ll smol = mx;
	ll bigg = 0;
	ll tiny = mx;
	for(int i=0; i<n; i++){
		if(arr[i]==maxi){
			if(i!=0)smol=min(smol, arr[i-1]);
			if(i!=n-1)smol=min(smol,arr[i+1]);
			if(i!=0)bigg=max(bigg, arr[i-1]);
			if(i!=n-1)bigg=max(bigg,arr[i+1]);
		}
		if(arr[i]==mini){
			if(i!=0)tiny=min(tiny, arr[i-1]);
			if(i!=n-1)tiny=min(tiny,arr[i+1]);
		}
	}
	sort(arr.begin(), arr.end());
	// use smol
	ll ans = min(maxi, arr[k-1]*2);
	for(int i=0; i<k; i++){
		if(arr[i]==smol){
			ans = min(maxi, arr[k]*2);
			break;
		}
	}
	// use bigg
	ans = max(ans, min(bigg, arr[k]*2));
	// use tiny
	/*
	if (k>=2){
		ll temp = min(mx, arr[k-1]*2);
		for(int i=0; i<k; i++){
			if(arr[i]==tiny){
				temp = min(mx, arr[k]*2);
				break;
			}
		}
		ans = max(ans, temp);
	} 
	*/
	// greedy
	ans = max(ans, arr[k]);
	set<int> kleast;
	for(int i=0; i<k; i++)kleast.insert(arr[i]);
	for(int i=0; i<n-1; i++){
		if(kleast.find(ori[i])!=kleast.end() && kleast.find(ori[i+1])!=kleast.end()){
			ans = max (ans, min(mx, arr[k]*2));
			break;
		}
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
