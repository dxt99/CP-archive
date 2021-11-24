#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

ll n,x;
ll dp[N];
ll coin[103];


int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	memset(dp,0,sizeof(dp));
	cin>>n>>x;
	for(int i=0;i<n;i++)cin>>coin[i];
	dp[0]=0;
	for(int i=0;i<n;i++){
		if(coin[i]<=x)dp[coin[i]]+=1;
		for(int j=coin[i]+1;j<=x;j++){
			if(dp[j-coin[i]]!=0)dp[j]=(dp[j]+dp[j-coin[i]])%Mod;
			//cout<<j<<"--";
		}
	}
	//for(int i=0;i<=x;i++)cout<<dp[i]<<"--";
	cout<<dp[x]<<endl;
}
