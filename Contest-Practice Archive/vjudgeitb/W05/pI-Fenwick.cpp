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

ll arr[maxN];
ll dp[maxN];

class fenwick{
	private:
		vl ft;
	public:
		fenwick(int n){
			ft.assign(n+1,0);
		}
		int rsq(int b){
			ll ret=0;
			for(;b;b-=(b&(-b)))ret=max(ret,ft[b]);
			return ret;
		}
		int rsq(int a,int b){
			return rsq(b)-(a==1?0:rsq(a-1));
		}
		void update(int i, ll val){
			for(;i<(int)ft.size();i+=(i&-i))ft[i]=max(ft[i],val);
		}
};

void solve(){
	ll n; cin>>n;
	for(int i=0;i<n;i++)cin>>arr[i];
	fenwick f(n);
	ll ans=0;
	for(int i=0;i<n;i++){
		dp[arr[i]]+=f.rsq(arr[i]-1)+1;
		f.update(arr[i],dp[arr[i]]);
		ans=max(dp[arr[i]],ans);
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

