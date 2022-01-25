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
	ll arr[n+5];
	queue<ll> cnt[n+5];
	for(int i=0;i<n;i++){
		cin>>arr[i];
		cnt[arr[i]].push(i);
	}
	vl ans;
	for(int i=0;i<n;i++){
		int mex=0;
		ll pos=0;
		while(!cnt[mex].empty()){
			while(!cnt[mex].empty()&&cnt[mex].front()<i)cnt[mex].pop();
			if(cnt[mex].empty())break;
			ll mini=cnt[mex].front();
			cnt[mex].pop();
			if(i>mini)break;
			pos=max(pos,mini);
			mex++;
		}
		if(mex>0)i=pos;
		ans.pb(mex);
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
	cin>>t;
 	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
