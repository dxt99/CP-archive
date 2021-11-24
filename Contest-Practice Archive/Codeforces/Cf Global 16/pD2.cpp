#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;

const int N = 1e5 + 3, Mod = 1e9 + 7;
const int maxn=1e3;

ll arr[N];
ll ord[N];
bool done[N];

ll binser(ll l,ll r,ll val){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	//printf("%lld",mid);
	if(ord[mid]==val)return mid;
	else if(ord[mid]>val)return binser(l,mid-1,val);
	else return binser(mid+1,r,val);
}

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

void solve(){
	memset(done,0,sizeof(done));
	memset(arr,0,sizeof(arr));
	memset(ord,0,sizeof(ord));
	ll n,m;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>arr[i*m+j];
			ord[i*m+j]=arr[i*m+j];
		}
	}
	fenwick seats(n*m);
	sort(ord,ord+n*m);
	ll ans=0;
	for(int i=0;i<n;i++){
	//	printf("%d\n",i);
		for(int j=0;j<m;j++){
			ll pos=binser(0,n*m-1,arr[i*m+j]);
			while(done[pos]&&pos>0)pos--;
			while(pos<n*m-1&&!done[pos+1]&&arr[i*m+j]==ord[pos+1]){
				pos++;
				if(pos%m==m-1)break;
			}
			cout<<pos<<"--";
			done[pos]=1;
			//cout<<seats.rsq(pos+1,m*(i+1))<<"==";
			ans+=(m*((pos)/m+1)-(pos+1)-seats.rsq(pos+1,m*((pos)/m+1)));
			seats.update(pos+1,1);
			//cout<<ans<<"--";
		}
	}
	cout<<ans<<endl;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr); 
	cout.tie(nullptr);
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		//cout<<"Case #"<<i+1<<": ";
		solve();
	}
}
