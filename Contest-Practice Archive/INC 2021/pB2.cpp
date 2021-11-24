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
const int maxN=1e7+3;

map<ll,bool> can;

void solve(){
	ll n; cin>>n;
	bool saw=0;
	can[0]=1;
	ll sum=0;
	for(int i=0;i<n;i++){
		ll x; cin>>x;
		sum+=x;
		if(x==2&&!saw){
			saw=1;
			continue;
		}
		ll cnt=can.size();
		ll idx=0;
		for(auto it=can.begin();idx<cnt;it++){
			if(can[it->fs]&&it->fs+x<maxN)can[it->fs+x]=1;
			idx++;
		}
	}
	if(sum%2==1){
		cout<<"NO"<<endl;
		return;
	}
	sum/=2;
	bool ret=0;
	if(can[sum])ret=1;
	if(saw){
		if(can[sum-1])ret=1;
		if(can[sum-2])ret=1;
	}
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

