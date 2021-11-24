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
	ll n,m; cin>>n>>m;
	bool y[n];
	for(int i=0;i<n;i++)y[i]=1;
	for(int i=0;i<m;i++){
		ll a,b,c; cin>>a>>b>>c;
		y[b-1]=0;
	}
	for(int i=0;i<n;i++){
		if(y[i]){
			for(int j=0;j<n;j++){
				if(i==j)continue;
				cout<<i+1<<" "<<j+1<<endl;
			}
			return;
		}
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

