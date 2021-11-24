#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

ll n;
ll dp[N];


ll ways(int x){
	if(x==0)return 0;
	if(dp[x]!=-1)return dp[x];
	int temp=x;
	dp[x]=INT_MAX;
	while(temp>0){
		dp[x]=min(dp[x],ways(x-temp%10)+1);
		temp/=10;
	}
	return dp[x];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	memset(dp,-1,sizeof(dp));
	cin>>n;
	cout<<ways(n)<<endl;
}
