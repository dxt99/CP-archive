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
const int maxN=1e3+3;

void solve(){
	ll a,b,c,k;
	cin>>a>>b>>c>>k;
	ll mini=max(a,b);
	mini=max(mini,c)*2-a-b-c-1;
	mini=max(mini,(ll)0);
	ll maxi=a+b+c-3;
	if(k>=mini&&k<=maxi)cout<<"YES\n";
	else cout<<"NO\n";
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
