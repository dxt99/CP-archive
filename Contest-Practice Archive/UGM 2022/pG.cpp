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
typedef vector<pair<pl,ll>> vlll;
typedef priority_queue <ll, vector<ll>, greater<ll>> minh;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e2+20;

int n;
vlll cost;


void solve(){
	cin>>n;
	ll sum=0;
	for(int i=0; i<n; i++){
		ll a,b,c; cin>>a>>b>>c;
		sum+=c;
		cost.pb(mp(mp(a,b),c));
	}
	sort(cost.begin(),cost.end());
	ll maxi = 0;
	for(int i=0; i<n; i++){
		ll tot = cost[i].sd;
		ll a = cost[i].fs.fs;
		ll b = cost[i].fs.sd;
		for(int j=i+1; j<n; j++){
			if(cost[j].fs.fs == a && cost[j].fs.sd == b){
				tot += cost[j].sd;
				continue;
			}
			if(cost[j].fs.fs > a && cost[j].fs.sd > b){
				tot += cost[j].sd;
				a = cost[j].fs.fs;
				b = cost[j].fs.sd;
				continue;
			}
		}
		maxi = max(tot,maxi);
	}
	cout<<sum-maxi<<endl;
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
