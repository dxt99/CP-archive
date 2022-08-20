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
	int n,m; cin>>n>>m;
	int arr[n+2][m+2];
	for(int i=0; i<=n+1; i++){
		for(int j=0; j<=m+1; j++)arr[i][j]=1;
	}
	for(int i=1; i<=n; i++){
		string s; cin>>s;
		for(int j=1; j<=m; j++){
			arr[i][j]=(s[j-1]-'0');
		}
	}
	int ans=0;
	int maxi=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(arr[i][j]==1){
				ans++;
			}
			int cnt=0;
			if(arr[i][j]==0)cnt++;
			if(arr[i][j+1]==0)cnt++;
			if(arr[i+1][j]==0)cnt++;
			if(arr[i+1][j+1]==0)cnt++;
			maxi = max(maxi,cnt);
		}
	}
	if(maxi==0)ans-=2;
	else if(maxi==1)ans-=1;
	cout<<ans<<endl;
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
