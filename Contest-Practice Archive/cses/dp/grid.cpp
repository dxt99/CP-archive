#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxn=1e3+3;

ll n;
ll dp[maxn][maxn];
char arr[maxn][maxn];


ll count(ll x,ll y){
	if(arr[x][y]=='*')return 0;
	if(x==n-1&&y==n-1)return dp[n-1][n-1]=1;
	if(dp[x][y]!=-1)return dp[x][y];
	dp[x][y]=0;
	dp[x][y]+=(count(x+1,y)+count(x,y+1));
	dp[x][y]%=Mod;
	return dp[x][y];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	for(int i=0;i<n;i++)for(int j=0;j<n;j++)cin>>arr[i][j];
	for(int i=0;i<=n;i++)arr[n][i]='*',arr[i][n]='*';
	cout<<count(0,0)<<endl;;
}
