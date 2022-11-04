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
	ll n,m; cin>>n>>m;
	if(n==2||m==2){
		cout<<max(n,m)<<endl;
		return;
	}
	ll len = min(n,m)/2;
	n--;
	m--;
	ll ans;
	if(min(n,m)%2==0){
		ans = ((n+(n-(2*(len-1)))));
		ans -= 2;
		ans += ((m+(m-(2*(len-1)))));
		ans*=len;
	}else{
		ans = ((n+(n-(2*(len-2)))));
		ans -= 2;
		ans += ((m+(m-(2*(len-2)))));
		ans*=(len-1);
		ans+= (max(n,m)-2*(len-1));
		ans++;
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t=1;
	//cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
