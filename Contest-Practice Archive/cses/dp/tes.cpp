#include<bits/stdc++.h>
#define pb push_back
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
 
const int N = 1e6 + 3, Mod = 1e9 + 7;
 
int n,x;
int dp[103][N];
int coin[N];
 
int ways(int pos,int rem){
	if(pos==n)return 0;
	if(rem<0)return 0;
	if(rem==0)return 1;
	if(dp[pos][rem])return dp[pos][rem];
	dp[pos][rem]+=(ways(pos+1,rem)+ways(pos,rem-coin[pos]));
	dp[pos][rem]%=Mod;
	return dp[pos][rem];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	cin>>n>>x;
	for(int i=0;i<n;i++)cin>>coin[i];
	
	cout<<ways(0,x)<<endl;
}
