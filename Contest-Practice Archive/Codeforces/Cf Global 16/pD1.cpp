#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vector<pair<ll,ll>>> vll;

const int N = 1e6 + 3, Mod = 1e9 + 7;

ll arr[N];
ll ord[N];
bool done[N];

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
	for(int i=0;i<m;i++){
		cin>>arr[i];
		ord[i]=arr[i];
	}
	fenwick seats(m);
	sort(ord,ord+m);
	ll ans=0;
	for(int i=0;i<m;i++){
		int j=m-1;
		while((ord[j]!=arr[i])||done[j])j--;
		done[j]=1;
		seats.update(j+1,1);
		//cout<<seats.rsq(j+1,m)<<"==";
		ans+=(m-(j+1)-seats.rsq(j+1,m)+1);
		//cout<<ans<<"--";
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
