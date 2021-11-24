#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define fs first
#define sd second
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<pair<ll,ll>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;
const int maxN=1e5+3;

class fenwick{
	private:
		vi ft;
	public:
		fenwick(int n){
			ft.assign(n+1,0);
		}
		int rsq(int b){
			int ret=0;
			for(;b;b-=(b&(-b)))ret+=ft[b];
			return ret;
		}
		int rsq(int a,int b){
			return rsq(b)-(a==1?0:rsq(a-1));
		}
		void update(int i, int val){
			for(;i<(int)ft.size();i+=(i&-i))ft[i]+=val;
		}
};

ll n,q;

void solve(){
	cin>>n>>q;
	fenwick col(n);
	fenwick row(n);
	for(int i=0;i<q;i++){
		ll j; cin>>j;
		if(j==1){
			ll b,x; cin>>b>>x;
			row.update(b,x);
		}else if(j==2){
			ll r,x; cin>>r>>x;
			col.update(r,x);
		}else{
			ll b1,k1,b2,k2;
			cin>>b1>>k1>>b2>>k2;
			ll ans=row.rsq(b1,b2);
			ans%=2;
			ans*=(k2-k1+1);
			ll ans2=col.rsq(k1,k2);
			ans2%=2;
			ans2*=(b2-b1+1);
			ans+=ans2;
			if(ans&1)cout<<"Ganjil"<<endl;
			else cout<<"Genap"<<endl;
		}
	}
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
