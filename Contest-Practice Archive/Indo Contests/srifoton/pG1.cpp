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
	ll n; cin>>n;
	vector<pair<pair<ll,ll>,ll>> time;
	for(int i=0;i<n;i++){
		ll x,y; cin>>x>>y;
		time.pb(mp(mp(x,y),i+1));
	}
	sort(time.begin(),time.end());
	vl ans;
	for(int i=0;i<n;i++){
		ll cur=0;
		bool f=1;
		for(int j=0;j<n;j++){
			if(i==j)continue;
			if(cur<=time[j].fs.fs){
				cur=time[j].fs.sd;
			}else{
				f=0;
				break;
			}
		}
		if(f)ans.pb(time[i].sd);
	}
	cout<<ans.size()<<endl;
	for(auto i:ans)cout<<i<<" ";
	cout<<endl;
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

