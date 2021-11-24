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

ll arr[N];
ll srt[N];

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

ll binser(ll l,ll r,ll val){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	//printf(".%d",mid);
	if(arr[mid]==val)return mid;
	if(arr[mid]>val&&arr[mid-1]<val)return mid;
	if(arr[mid]>val) return binser(l,mid-1,val);
	if(arr[mid]<val) return binser(mid+1,r,val);
}

void solve(){
	ll n; cin>>n;
	set<ll> s;
	for(int i=0;i<n;i++){
		cin>>srt[i];
		s.insert(srt[i]);
	}
	int sz=0;
	auto it=s.begin();
	while(it!=s.end()){
		arr[sz]=*it;
		it++;
		sz++;
	}
	fenwick f(n);
	ll ans=0;
	for(int i=0;i<n;i++){
		ll pos=binser(0,sz-1,srt[i]);
		ans+=min(f.rsq(pos),f.rsq(pos+2,n));
		f.update(pos+1,1);
	}
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
