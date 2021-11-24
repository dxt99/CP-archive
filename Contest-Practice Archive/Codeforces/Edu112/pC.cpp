#include<bits/stdc++.h>
#define pb push_back
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;

const int N = 1e6 + 3, Mod = 1e9 + 7;

void solve(){
	int n;
	cin>>n;
	int arr[2][n];
	for(int j=0;j<2;j++)for(int i=0;i<n;i++)cin>>arr[j][i];
	int pre1[n];
	int pre2[n];
	pre1[0]=0;
	pre2[0]=0;
	for(int i=1;i<n;i++)pre1[i]=(pre1[i-1]+arr[0][n-i]);
	for(int i=0;i<n-1;i++)pre2[i+1]=(pre2[i]+arr[1][i]);
	int ans=INT_MAX;
	for(int i=0;i<n;i++)ans=min(ans,max(pre1[i],pre2[n-i-1]));
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
