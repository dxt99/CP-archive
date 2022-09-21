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
	ll n,m,tot;
	cin>>m>>n>>tot;
	ll mini=n*m;
	ll maxi=mini+n*(m-2);
	bool ret=0;
	if(tot>=mini&&tot<=maxi)ret=1;
	else if((tot-maxi)%2==0)ret=1;
	else if((n>1)&&(m>2)&&tot>=mini+1)ret=1;
	if(ret)cout<<"YES\n";
	else cout<<"NO\n";
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}

