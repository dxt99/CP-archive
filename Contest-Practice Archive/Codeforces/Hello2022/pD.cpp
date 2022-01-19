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
typedef vector<pair<ll,pl>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

void solve(){
	int n; cin>>n;
	int arr[2*n][2*n];
	int ans=0;
	for(int i=0;i<2*n;i++){
		for(int j=0;j<2*n;j++){
			cin>>arr[i][j];
			if(i>=n&&j>=n){
				ans+=arr[i][j];
				arr[i][j]=0;
			}
		}
	}
	int dp[2*n+1][2*n+1];
	for(int i=0;i<=2*n;i++){
		for(int j=0;j<=2*n;j++){
			dp[i][j]=-1;
			if(i>=n&&j>=n)dp[i][j]=0;
			if(i==2*n||j==2*n)dp[i][j]=INT_MAX;
		}
	}
	for(int i=2*n-1;i>-1;i--){
		for(int j=2*n-1;j>-1;j--){
			if(i>=n&&j>=n)continue;
			dp[i][j]=arr[i][j]+min(dp[i+1][j],dp[i][j+1]);
		}
	}
	/*
	for(int i=0;i<2*n;i++){
		for(int j=0;j<2*n;j++){
			cout<<dp[i][j];
		}
		cout<<endl;
	}
	*/
	int mini=min(dp[0][0],arr[0][2*n-1]);
	mini=min(dp[0][0],arr[2*n-1][0]);
	for(int i=1;i<n;i++){
		cout<<mini<<endl;
		mini=min(mini,arr[2*n-1][i]+dp[2*n-1][i]);
		mini=min(mini,arr[i][2*n-1]+dp[i][2*n-1]);
	}
	cout<<ans+mini<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

