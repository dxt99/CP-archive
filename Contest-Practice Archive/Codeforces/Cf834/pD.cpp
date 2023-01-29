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

ll log(ll n, ll m){
	ll cnt=0;
	while(n%m==0){
		n/=m;
		cnt++;
	}
	return cnt;
}

void solve(){
	ll n,m; cin>>n>>m;
	ll cnt2=log(n,2);
	ll cnt5=log(n,5);
	ll ans=1;
	while(1){
		if(cnt2==cnt5){
			if(ans*10<=m){
				cnt2++;
				cnt5++;
				ans*=10;
				continue;
			}else break;
		}
		if(cnt2>cnt5){
			if(ans*5<=m){
				cnt5++;
				ans*=5;
				continue;
			}else break;
		}
		if(cnt2<cnt5){
			if(ans*2<=m){
				cnt2++;
				ans*=2;
				continue;
			}else break;
		}
	}
	//cout<<cnt2<<" "<<cnt5<<" ";
	ans *= (m/ans);
	cout<<n*ans<<endl;
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
