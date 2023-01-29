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

const int N = 3e5 + 3, Mod = 1e9 + 7;
const int maxN=1e3+3;

//segment tree (single update)
ll a[N]; //tree source
struct info {
	int x;
} d[maxN * 4]; //tree storage
 
info operator + (info a, info b) {
	info c;
	c.x = min(a.x, b.x);
	return c;
} //merging two datas (ans)
 
void build(int k, int l, int r) { //(1,1,n)
	if (l == r) {
		d[k] = (info) {a[l]};
	} else {
		int mid = (l + r) / 2;
		build(k * 2, l, mid);
		build(k * 2 + 1, mid + 1, r);
		d[k] = d[k * 2] + d[k * 2 + 1]; //operator +
	}
}
 
//rebuild, only with node x, change the array directly
void update(int k, int l, int r, int x) { //(1,1,n,node)
	if (l == r) {
		d[k] = (info) {a[l]};
	} else {
		int mid = (l + r) / 2;
		if (x <= mid) update(k * 2, l, mid, x);
		else update(k * 2 + 1, mid + 1, r, x);
		d[k] = d[k * 2] + d[k * 2 + 1]; //operator +
	}
}
 
info query(int k, int l, int r, int x, int y) { //(1,1,n,leftq,rightq)
	if (l == x && r == y) {
		return d[k];
	} else {
		int mid = (l + r) / 2;
		if (y <= mid) return query(k * 2, l, mid, x, y);
		else if (x > mid) return query(k * 2 + 1, mid + 1, r, x, y);
		else return query(k * 2, l, mid, x, mid) + query(k * 2 + 1, mid + 1, r, mid + 1, y); //operator +
	}
}

vl arr(N);
vl ans(N);
void solve(){
	ll n; cin>>n;
	vll p;
	ll cur = n;
	for(int i=1; i<=n; i++){
		cin>>arr[i];
		if(arr[i]==-1){
			ans[i]=cur;
			cur--;
			continue;
		}
		p.pb(mp(-1*arr[i], i));
	}
	sort(p.begin(), p.end());
	for(int i=0; i<n+3; i++)a[i]=n+1;
	build(1,1,n+3);
	for(int i=n; i>0; i--){
		ll tmp = arr[i];
		ll nxt = tmp+1;
		if(tmp==-1){
			tmp = n+1;
			nxt = n+2;
		}
		a[tmp]=i;
		update(1,1,n+3,tmp);
		if(tmp>(ll)query(1,1,n+3,nxt,n+3).x){
			cout<<-1<<endl;
			return;
		}
	}

	for(auto k: p){
		ans[k.sd]=cur;
		cur--;
	}
	for(int i=1; i<=n; i++){
		cout<<ans[i]<<" ";
	}
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
