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
	int n,m,p; cin>>n>>m>>p;
	vl arr(n+1, 0);
	vl ans(n+1, 0);
	vll ls[n+1];
	for(int i=0; i<m; i++){
		ll l, r, v;
		cin>>l>>r>>v;
		ls[r].pb(mp(l,v));
	}
	vll fin[n+1];
	for(int i=n; i>0; i--){
		sort(ls[i].begin(), ls[i].end());
		ll sz = ls[i].size();
		if(sz==0)continue;
		ll fsCur = ls[i][sz-1].fs;
		ll vCur = ls[i][sz-1].sd;
		for(int j=0; j<sz-1; j++){
			ll fsTemp = ls[i][j].fs;
			ll vTemp = ls[i][j].sd;
			if(fsTemp == fsCur){
				if(vTemp != vCur){
					cout<<"None"<<endl;
					return;
				}
			}else{
				ls[fsCur-1].pb(mp(fsTemp, (p+vTemp-vCur)%p));
			} 
		}
		fin[i].pb(ls[i][sz-1]);
	}
	for(int i=1; i<=n; i++){
		arr[i]=arr[i-1];
		if(fin[i].size()==0)continue;
		ll fsCur = fin[i][0].fs;
		ll valCur = fin[i][0].sd;
		ans[i]=(p+valCur-(p+arr[i]-arr[fsCur-1])%p)%p;
		arr[i]+=ans[i];
	}
	for(int i=1; i<=n; i++)cout<<ans[i]<<" ";
	cout<<endl;
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
