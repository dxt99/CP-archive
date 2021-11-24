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
	vll seg;
	ll tar; cin>>tar;
	ll x,y; cin>>x>>y;
	while(x!=0||y!=0){
		seg.pb(mp(x,-1*y));
		cin>>x>>y;
	}
	sort(seg.begin(),seg.end());
	ll cur=0;
	ll i=0;
	vll segans;
	while(i<seg.size()&&cur<tar){
		ll best=i;
		while(i<seg.size()&&seg[i].fs<=cur){
			if(seg[i].sd<seg[best].sd)best=i;
			i++;
		}
		if(seg[best].fs<=cur&&cur<seg[best].sd*-1){
			cur=seg[best].sd*-1;
			segans.pb(seg[best]);
		}else break;
	}
	if(cur<tar){
		cout<<0<<endl;
	}else{
		cout<<segans.size()<<endl;
		for(auto p:segans)cout<<p.fs<<" "<<p.sd*-1<<endl;
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
		cout<<"\n";
	}
}
