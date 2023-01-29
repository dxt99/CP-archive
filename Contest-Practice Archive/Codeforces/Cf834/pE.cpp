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
	ll n, h; cin>>n>>h;
	vl arr(n+1);
	arr[0]=0;
	ll dp[n+1][3][2];
	for(int i=0; i<=n; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<2; k++){
				dp[i][j][k]=-1;
			}
		}
	}
	dp[0][0][0]=h;
	for(int j=0; j<=2; j++){
		for(int k=0; k<=1; k++){
			dp[0][j][k]=h * (1<<j);
			if(k)dp[0][j][k]*=3;
		}
	}
	for(int i=1; i<=n; i++)cin>>arr[i];
	sort(arr.begin(), arr.end());
	
	for(int i=1; i<=n; i++){
		for(int j=0; j<3; j++){
			for(int k=0; k<2; k++){
				if(dp[i-1][j][k]>arr[i]){
					dp[i][j][k]=max(dp[i][j][k],dp[i-1][j][k]+arr[i]/2);
				}
				for(int p=0; p+j<3; p++){
					for(int q=0; q+k<2; q++){
						ll temp = dp[i][j][k]*(1<<p);
						if(q)temp*=3;
						dp[i][p+j][q+k]=max(dp[i][p+j][q+k],temp);
					}
				}
			}
		}
	}
	ll ans=0;
	for(int i=1; i<=n; i++){
		ll f=0;
		for(int j=0; j<3; j++){
			for(int k=0; k<2; k++){
				if(dp[i][j][k]!=-1)f=1;
			}
		}
		if(!f){
			break;
		}
		ans=i;
	}
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
