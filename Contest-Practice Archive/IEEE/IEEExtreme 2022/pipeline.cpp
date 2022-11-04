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
	int n,m,d; cin>>n>>m>>d;
	ll arr[d+2][n+2][m+2]; //[d][n][m]
	for(int i=0; i<=d+1; i++){
		for(int j=0; j<=n+1; j++){
			for(int k=0; k<=m+1; k++){
				arr[i][j][k]=0;
			}
		}
	}
	ll total=0;
	for(int i=1; i<=d; i++){
		for(int j=1; j<=n; j++){
			string s; cin>>s;
			for(int k=1; k<=m; k++){
				if(s[k-1]=='*')arr[i][j][k]=3;
				else if (s[k-1]=='o')arr[i][j][k]=2;
				total+= arr[i][j][k];
			}
		}
	}
	ll cnt=0;
	ll sumOdd = 0;
	ll sumEven = 0;
	for(int i=1; i<=d; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=m; k++){
				ll sum = arr[i][j][k+1];
				sum += arr[i][j][k-1]; 
				sum += arr[i][j+1][k];
				sum += arr[i][j-1][k];
				sum += arr[i+1][j][k];
				sum += arr[i-1][j][k];
				if((i+j+k)%2)sumOdd+=arr[i][j][k];
				else sumEven += arr[i][j][k];
				if(arr[i][j][k]>sum){
					cout<<"NO"<<endl;
					return;
				}else if(arr[i][j][k]==sum){
					cnt++;
				} 
			}
		}
	}
	if(total%2 || sumOdd!=sumEven){
		cout<<"NO"<<endl;
	}else{
		cout<<"YES"<<endl;
	}
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
