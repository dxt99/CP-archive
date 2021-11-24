#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

int n,x;
ll coin[103];
ll dp[N];

ll ways(ll rem){
	if(rem==0)return 1;
	if(dp[rem]!=-1)return dp[rem];
	dp[rem]=0;
	for(int i=0;i<n;i++)if(coin[i]<=rem)dp[rem]=(dp[rem]+ways(rem-coin[i])%Mod)%Mod;
	return dp[rem];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	memset(dp,-1,sizeof(dp));
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>coin[i];
	}
	cout<<ways(x)<<endl;
}
