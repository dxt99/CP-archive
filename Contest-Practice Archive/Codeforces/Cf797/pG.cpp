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
const int maxN=1e5+3;

//segment tree (single update)
ll a[maxN]; //tree source
struct info {
	ll l,r, cnt;
} d[maxN * 4]; //tree storage

void clear(){
	for(int i=0; i<maxN; i++)a[i]=0;
	for(int i=0; i<4*maxN; i++)d[i]={0,0};
}

 
info operator + (info a, info b) {
	info c;
	c.l = a.l;
	c.r = min(b.r,a.r);
	c.cnt = a.cnt+b.cnt;
	if (a.r<=b.l) c.cnt--;
	if (b.l>b.r && a.r<=b.r) c.cnt--;
	return c;
} //merging two datas (ans)
 
void build(int k, int l, int r) { //(1,1,n)
	if (l == r) {
		d[k] = (info) {a[l],a[l], 1};
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
		d[k] = (info) {a[l],a[l], 1};
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

void solve(){
	ll n,m; cin>>n>>m;
	for(int i=1; i<=n; i++)cin>>a[i];
	build(1,1,n);
	while(m--){
		int i,d;
		cin>>i>>d;
		a[i]-=d;
		update(1,1,n,i);
		cout<<query(1,1,n,1,n).cnt<<" ";
	}
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
