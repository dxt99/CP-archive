#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

ll dp[N];

ll ways(ll k){
	if(k<0)return 0;
	if(dp[k])return dp[k];
	for(int i=1;i<7;i++){
		dp[k]+=ways(k-i);
		dp[k]=dp[k]%Mod;
	}
	return dp[k];
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	ll n;
	cin>>n;
	
	dp[0]=1;
	dp[1]=1;
	cout<<ways(n)<<endl;
}
