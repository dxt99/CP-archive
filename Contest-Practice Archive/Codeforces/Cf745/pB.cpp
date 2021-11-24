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
const int maxN=1e5+3;

void solve(){
	ll n,m,k;
	cin>>n>>m>>k;
	bool yes=1;
	if(m<n-1)yes=0;
	if(n<100000&&2*m>n*n-n)yes=0;
	if(n==1&&k<2)yes=0;
	if(n==2&&k<3)yes=0;
	if(n<100000&&2*m==n*n-n&&k>=3){
		cout<<"YES"<<endl;
		return;
	}else if(n>=3&&k<4)yes=0;
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
