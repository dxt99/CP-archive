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

vlll arr;

//segment tree (single update)
ll a[maxN]; //tree source
struct info {
	ll x;
} d[maxN * 4]; //tree storage
 
info operator + (info a, info b) {
	info c;
	c.x = max(a.x, b.x);
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

void solve(){
	ll n; cin>>n;
	for(int i=0; i<n; i++){
		ll p, l, val;
		cin>>p>>l>>val;
		arr.pb(mp(-1*p,mp(l, val)));
	}
	sort(arr.begin(), arr.end());
	build(1, 1, maxN);
	for(auto t:arr){
		ll l = t.sd.fs;
		ll val = t.sd.sd;
		auto ans = query(1, 1, maxN, l+1, maxN);
		ll maxi = ans.x;
		a[l] = max(a[l], val + maxi);
		update(1, 1, maxN, l);
	}
	ll ans = 0;
	for(int i=0; i<maxN; i++){
		ans = max(a[i], ans);
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
