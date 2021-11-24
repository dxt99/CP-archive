#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

ll n,x;
ll dp[103][N];
ll coin[103];

ll ways(int pos,ll rem){
	if(rem==0)return 1;
	if(pos==n)return 0;
	if(rem<0)return 0;
	if(dp[pos][rem]!=-1)return dp[pos][rem];
	dp[pos][rem]=(ways(pos+1,rem)%Mod+ways(pos,rem-coin[pos])%Mod)%Mod;
	return dp[pos][rem];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	memset(dp,-1,sizeof(dp));
	cin>>n>>x;
	for(int i=0;i<n;i++)cin>>coin[i];
	
	cout<<ways(0,x)<<endl;
}
