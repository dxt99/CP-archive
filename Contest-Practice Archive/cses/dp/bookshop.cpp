#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<ll,ll> pl;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+1;

int n,tar;
int w[maxN];
int v[maxN];
int dp[maxN][100001];

int count(int i,int cur){
	if(cur<0)return -1*Mod;
	if(i==n)return 0;
	if(dp[i][cur]>=0)return dp[i][cur];
	int& ans=dp[i][cur];
	ans=0;
	ans=max(count(i+1,cur),count(i+1,cur-w[i])+v[i]);
	return ans;
}

void solve(){
	cin>>n>>tar;
	for(int i=0;i<n;i++)cin>>w[i];
	for(int i=0;i<n;i++)cin>>v[i];
	for(int i=0;i<n;i++)for(int j=0;j<=tar;j++)dp[i][j]=-1;
	cout<<count(0,tar)<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
