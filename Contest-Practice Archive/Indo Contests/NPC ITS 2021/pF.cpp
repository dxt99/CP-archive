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

const ll inv=5e8+4;

void solve(){
	ll n,s;
	cin>>n>>s;
	n%=Mod;
	s%=Mod;
	//cout<<n<<s<<endl;
	s*=n;
	s=s%Mod;
	ll ans=n+(s);
	ans%=Mod;
	//cout<<ans<<endl;
	if(s<n)s+=Mod;
	ans*=(s-n+1);
	ans%=Mod;
	ans*=inv;
	ans%=Mod;
	cout<<ans<<endl;
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
