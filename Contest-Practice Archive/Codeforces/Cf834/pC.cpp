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
	ll l,r,x; cin>>l>>r>>x;
	ll a,b; cin>>a>>b;
	queue<pl> q;
	q.push(mp(a,0));
	ll ans=-1;
	while(1 & !q.empty()){
		pl p = q.front();
		q.pop();
		if(p.sd > 4)break;
		if(p.fs==b){
			ans = p.sd;
			break;
		}
		if(abs(p.fs-b)>=x){
			ans = p.sd+1;
			break;
		}
		if(abs(l-p.fs)>=x){
			q.push(mp(l,p.sd+1));
		}
		if(abs(r-p.fs)>=x){
			q.push(mp(r,p.sd+1));
		}
	}
	while(!q.empty())q.pop();
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
