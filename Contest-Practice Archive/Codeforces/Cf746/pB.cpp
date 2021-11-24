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
	ll x,n;
	cin>>n>>x;
	ll arr[n];
	ll srt[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		srt[i]=arr[i];
	}
	sort(arr,arr+n);
	if(x<=n/2){
		cout<<"YES"<<endl;
		return;
	}
	bool yes=1;
	int i=n-x;
	for(;i<x;i++){
		if(srt[i]!=arr[i])yes=0;
	}
	if(yes)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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
