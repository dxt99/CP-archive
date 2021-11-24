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
	bool flag=1;
	vector<pair<pair<ll,ll>,ll>> ap;
	vl ans(n+1);
	for(int i=0;i<n;i++){
		ll x,y; cin>>x>>y;
		ap.pb(mp(mp(x,y),(ll)i+1));
		ans[i+1]=-1;
	}
	sort(ap.begin(),ap.end());
	priority_queue<pair<ll,ll>> pq;
	ll idx=0;
	for(int i=1;i<=n;i++){
		if(idx<n)while(ap[idx].fs.fs==i){
			pq.push(mp(-1*ap[idx].fs.sd,ap[idx].sd));
			idx++;
		}
		if(pq.empty()||pq.top().fs*-1<i){
			flag=0;
			break;
		}else{
			ans[i]=pq.top().sd;
			pq.pop();
		}
	}
	if(!flag)cout<<"impossible";
	else for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<endl;
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

