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
	int n; cin>>n;
	ll ans=0;
	if(n==1)ans=1;
	else if(n==2)ans=4;
	else if(n==3)ans=7;
	else if(n==4)ans=10;
	else if(n==5)ans=11;
	else{
		ans=11;
		ll cnt = (n-5)/6;
		ans+=(16*cnt);
		n=n%6;
		if(n==0)ans+=5;
		else if(n==1)ans+=6;
		else if(n==2)ans+=9;
		else if(n==3)ans+=12;
		else if(n==4)ans+=15;
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
