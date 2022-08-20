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
	ll n,q;
	cin>>n>>q;
	vl arr(n);
	for(int i=0; i<n; i++)cin>>arr[i];
	vl pre(n);
	vl got(n);
	for(int i=0; i<n; i++)pre[i]=0;
	for(int i=0; i<n; i++)got[i]=0;
	ll cur = 0;
	got[0]=1;
	for(int i=1; i<n; i++){
		if(arr[cur]>arr[i]){
			pre[cur]++;
		}
		else{
			pre[i]++;
			cur=i;
			got[cur]=i;
		}
	}
	for(int i=0; i<q; i++){
		ll pos, r; cin>>pos>>r;
		pos--;
		//cout<<"ANS: ";
		if(r<n-1){
			if(pre[pos]==0)cout<<0<<endl;
			else cout<<min(max((ll)0,r-got[pos]+1), pre[pos])<<endl;
		}
		else if(pos!=cur)cout<<pre[pos]<<endl;
		else cout<<pre[pos] + max(r-n+1, (ll)0)<<endl;
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
	}
}
