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
const int maxN=1e5+3;

void solve(){
	int n;
	cin>>n;
	ll arr[n][5];
	for(int i=0;i<n;i++){
		for(int j=0;j<5;j++){
			cin>>arr[i][j];
		}
	}
	bool yes=0;
	for(int i=0;i<5;i++){
		for(int j=i+1;j<5;j++){
			yes=1;
			ll l=0;
			ll r=0;
			for(int k=0;k<n;k++){
				if(arr[k][i]==0&&arr[k][j]==0){
					yes=0;
					break;
				}
				l+=(arr[k][i]==1);
				r+=(arr[k][j]==1);
			}
			if(l<n/2||r<n/2)yes=0;
			if(yes)break;
		}
		if(yes)break;
	}
	if(yes)cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
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
