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
	int n,k; cin>>n>>k;
	vll arr;
	vl ar1,ar2;
	for(int i=0;i<n;i++){
		int x; cin>>x;
		ar1.pb(x);
	}
	for(int i=0;i<n;i++){
		int x; cin>>x;
		ar2.pb(x);
	}
	for(int i=0;i<n;i++){
		arr.pb(mp(ar1[i],ar2[i]));
	}
	sort(arr.begin(),arr.end());
	for(int i=0;i<n;i++){
		if(arr[i].fs<=k)k+=arr[i].sd;
	}
	cout<<k<<endl;
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
