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
	ll n,k; cin>>n>>k;
	string x; cin>>x;
	vl a(n);
	for(int i=0; i<n; i++){
		if(x[i]=='B')a[i]=1;
		else a[i]=0;
	}
	for(int i=1; i<n; i++)a[i]+=a[i-1];
	ll maxi = a[k-1];
	for(int i=k; i<n; i++){
		maxi = max(maxi, a[i]-a[i-k]);
	}
	cout<<k-maxi<<endl;
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
