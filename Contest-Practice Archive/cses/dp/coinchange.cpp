#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

int n,x;
int coin[N];
int dp[N];

int ways(int rem){
	if(!rem)return 0;
	if(rem<0)return INT_MAX-1;
	if(dp[rem])return dp[rem];
	dp[rem]=INT_MAX-1;
	for(int i=0;i<n;i++)dp[rem]=min(dp[rem],ways(rem-coin[i])+1);
	return dp[rem];
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>coin[i];
	}
	if(ways(x)>INT_MAX-20)cout<<-1<<endl;
	else cout<<ways(x)<<endl;
}
