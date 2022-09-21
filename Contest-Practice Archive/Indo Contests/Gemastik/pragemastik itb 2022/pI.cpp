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
	ll n,m,q; cin>>n>>m>>q;
	ll arr[n+1]; arr[0]=0;
	ll sum[n+1]; sum[0]=0;
	vl b(m+2);
	bool f[m+4]; f[0]=0; f[m+1]=0;
	ll bef = 0;
	b[0]=0;
	b[m+1] = n;
	for(int i=1; i<=n; i++)cin>>arr[i];
	for(int i=1; i<=n; i++)sum[i]=arr[i]+sum[i-1];
	for(int i=1; i<=m; i++){
		cin>>b[i];
		f[i]=0;
		for(int j=bef+1; j<=b[i]; j++){
			arr[j]+=arr[j-1];
		}
		bef = b[i]+1;
	}
	for(int j=bef+1; j<=b[m+1]; j++)arr[j]+=arr[j-1];
	
	for(int cc=0; cc<q; cc++){
		char t; cin>>t;
		if(t=='B'){
			int x; cin>>x;
			f[x]^=1;
		}else{
			ll ans = 0;
			ll l, r; cin>>l>>r;
			//l -> b[idx], sum, r
			int idxL = lower_bound(b.begin(), b.end(), l) - b.begin();
			int idxR = lower_bound(b.begin(), b.end(), r) - b.begin();
			if(idxL==idxR){
				// case 2 l, r
				if(f[idxL]){
					r = b[idxR]-(r-b[idxR-1]);
					l = b[idxR]-(l-b[idxR-1]) + 1;
					ans = arr[l];
					if(r!=b[idxR-1])ans-=arr[r];
				}else{
					ans = arr[r];
					if(l-1!=b[idxL-1])ans-=arr[l-1];
				}
				cout<<ans<<endl;
				continue;
			}
			// case 1, l -> b[idxL], sum, b[idxR] -> r
			if(f[idxL]){
				ans+=arr[b[idxL-1]+1+b[idxL]-l];
			}else{
				ans+=arr[b[idxL]];
				if(l-1!=b[idxL-1])ans-=arr[l-1];
			}
			if(f[idxR]){
				// flipped
				ans+=arr[b[idxR]];
				r = b[idxR]-(r-b[idxR-1]);
				if(r!=b[idxR-1])ans-=arr[r];
			}else{
				ans+=arr[r];

			}
			ans += (sum[b[idxR-1]]-sum[b[idxL]]);
			cout<<ans<<endl;
		}
	}
	
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
