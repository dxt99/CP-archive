#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;

ll cnt[N];
ll arr[N];
ll dp[N];
 
 ll count(ll n){
 	if(n<=0)return 0;
 	if(cnt[n]==0)return dp[n]=count(n-1);
 	if(dp[n]!=-1)return dp[n];
 	return dp[n]=max(cnt[n]*n+count(n-2),count(n-1));
 }
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	memset(dp,-1,sizeof(dp));
	
	ll n;
	cin>>n;
	ll maxi=0;
	ll ans=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		cnt[arr[i]]++;
		maxi=max(maxi,arr[i]);
	}
	cout<<count(maxi)<<endl;
}
