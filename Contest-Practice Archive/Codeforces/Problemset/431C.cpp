#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

ll dp[1000][2];
ll n,k,d;
 
ll ways(ll n,int f){
	if(n==0&&f==0)return 1;
	if(n==0&&f==1)return 0;
	if(n<0)return 0;
	if(dp[n][f]!=-1)return dp[n][f];
	dp[n][0]=0;
	dp[n][1]=0;
	for(int j=1;j<d;j++){
		dp[n][1]+=ways(n-j,1);
		dp[n][1]%=Mod;
		dp[n][0]+=ways(n-j,0);
		dp[n][0]%=Mod;
	}
	for(int j=d;j<=k;j++){
		dp[n][1]+=(ways(n-j,1)+ways(n-j,0));
		dp[n][1]%=Mod;
	}
	return dp[n][f];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	memset(dp,-1,sizeof(dp));
	cin>>n>>k>>d;
	cout<<ways(n,1)<<endl;
}
