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

map<ll,ll> dp;

void solve(){
	int n; cin>>n;
	int arr[n];
	for(int i=0;i<n;i++){
		int x; cin>>x;
		arr[i]=x;
		dp[x]=dp[x-1]+1;
	}
	int ans=0;
	for(int i=0;i<=n;i++){
		int j=arr[i];
		if(dp[ans].size()<dp[j].size())ans=j;
	}
	cout<<dp[ans].size()<<endl;
	for(auto k:dp[ans])cout<<k<<" ";
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
