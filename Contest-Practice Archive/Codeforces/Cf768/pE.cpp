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

int arr[N];
int l[N];
int r[N];
vll seg;

void solve(){
	int n; cin>>n;
	for(int i=1;i<=n;i++){
		int x; cin>>x;
		if(l[x]==0)l[x]=i;
		else r[x]=i;
	}
	for(int i=1;i<=n;i++){
		if(r[i]!=0){
			seg.pb(mp(l[i],r[i]));
		}
	}
	sort(seg.begin(),seg.end());
	int ans=0;
	int curr=0;
	for(int i=0;i<seg.size();i++){
		pl c=seg[i];
		if(c.fs>curr){
			ans+=(c.sd-c.fs-1);
			curr=c.sd;
		}else{
			ll maxi=c.sd;
			while(i!=seg.size()-1&&seg[i+1].fs<curr){
				i++;
				c=seg[i];
				maxi=max(c.sd,maxi);
			}
			if(maxi<curr)continue;
			ans+=(maxi-curr-1);
			curr=maxi;
		}
	}
	cout<<ans<<endl;
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
