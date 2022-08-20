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
	for(int i=0; i<n; i++){
		cin>>arr[i];
		ori[i]=arr[i];
		if(i>0)maxi=max(maxi,min(arr[i],arr[i-1]));
	}
	sort(arr.begin(), arr.end());

	set<int> kleast;
	for(int i=0; i<k; i++)kleast.insert(arr[i]);
	// use existing
	ll ans = min(maxi, arr[k]*2);
	// use one only
	ll bigg = arr[n-1];
	ans = max(ans, min(bigg, arr[k-1]*2));
	for(int i=0; i<n; i++){
		if(ori[i]==bigg){
			if((i!=0 && kleast.find(ori[i-1])!=kleast.end() )|| 
				(i!=n-1 && kleast.find(ori[i+1])!=kleast.end())){
					ans = max(ans, min(bigg, arr[k]*2));
					break;
				}
		}
	}
	// use none
	if(k>=2)for(int i=0; i<n-1; i++){
		ll cnt=0;
		if(kleast.find(ori[i])!=kleast.end())cnt++;
		if(kleast.find(ori[i+1])!=kleast.end())cnt++;
		ans = max(ans, min(mx, arr[k-2+cnt]*2));
		if(cnt == 2)break;
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
