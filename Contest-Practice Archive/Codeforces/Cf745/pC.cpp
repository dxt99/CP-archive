#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=5e3+3;

ll arr[maxN][maxN];

void solve(){
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++)for(int j=0;j<m;j++){
		char x;
		cin>>x;
		arr[i][j]=x-'0';
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(i>0)arr[i][j]+=arr[i-1][j];
			if(j>0)arr[i][j]+=arr[i][j-1];
			if(i>0&&j>0)arr[i][j]-=arr[i-1][j-1];
			//cout<<arr[i][j]<<";";
		}
		//cout<<endl;
	}
	ll ans=16;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			for(int k=i+4;k<n;k++){
				for(int l=j+3;l<m;l++){
					ll temp=arr[k-1][l-1]+arr[i][j];
					temp-=(arr[i][l-1]+arr[k-1][j]);
					if(temp>16)break;
					//cout<<temp<<endl;
					//up zeroes - ones
					temp+=(l-1-j);
					temp-=(arr[i][l-1]-arr[i][j]);
					if(i>0)temp-=(arr[i-1][j]-arr[i-1][l-1]);
					if(temp>16)break;
					//cout<<temp<<endl;
					//down zeroes - ones
					temp+=(l-1-j);
					temp-=(arr[k][l-1]-arr[k][j]);
					temp+=(arr[k-1][l-1]-arr[k-1][j]);
					if(temp>16)break;
					//cout<<temp<<endl;
					//left zeroes - ones
					temp+=(k-1-i);
					temp-=(arr[k-1][j]-arr[i][j]);
					if(j>0)temp-=(arr[i][j-1]-arr[k-1][j-1]);
					if(temp>16)break;
					//cout<<temp<<endl;
					//right zeroes - ones
					temp+=(k-1-i);
					temp-=(arr[k-1][l]-arr[i][l]);
					temp+=(arr[k-1][l-1]-arr[i][l-1]);
					if(temp>16)continue;
					ans=min(ans,temp);
				}
			}
		}
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
