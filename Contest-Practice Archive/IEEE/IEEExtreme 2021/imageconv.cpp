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
const int maxN=5e3+3;

ll r,c;
ll a,b;
char arr[maxN][maxN];
char tar[maxN][maxN];

void solve(){
	cin>>r>>c;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++)cin>>arr[i][j];
	}
	cin>>a>>b;
	for(int i=0;i<a;i++){
		for(int j=0;j<b;j++)cin>>tar[i][j];
	}
	ll cnt=0;
	for(int i=0;i+a-1<r;i++){
		for(int j=0;j+b-1<c;j++){
			bool f=1;
			for(int k=0;k<a&&f;k++){
				for(int l=0;l<b&&f;l++){
					if(tar[k][l]=='?')continue;
					if(tar[k][l]!=arr[i+k][j+l])f=0;
				}
			}
			if(f)cnt++;
		}
	}
	cout<<cnt<<endl;
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

