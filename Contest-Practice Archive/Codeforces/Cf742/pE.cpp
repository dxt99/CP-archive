#include<bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int N=1e6+3, Mod=1e9+7;
const int maxN=2e5+2;


//segment tree (single update)
int a[maxN]; //tree source, 1-based array
struct info {
	int l, r, fl, fr, sz;
	long long tot;
} d[maxN * 4]; //tree storage, 1-based
 
info operator + (info a, info b) {
	info c;
	c.l = a.l;
	c.r = b.r;
	c.sz = a.sz + b.sz;
	c.fl = (a.fl == a.sz && a.r <= b.l) ? (a.fl + b.fl) : a.fl;
	c.fr = (b.fr == b.sz && a.r <= b.l) ? (b.fr + a.fr) : b.fr;
	c.tot = a.tot + b.tot + ((a.r <= b.l) ? (1ll * a.fr * b.fl) : 0);
	return c;
} //merging two datas (ans)
 
void build(int k, int l, int r) { //(1,1,n)
	if (l == r) {
		d[k] = (info) {a[l], a[l], 1, 1, 1, 1ll};
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
		d[k] = (info) {a[l], a[l], 1, 1, 1, 1ll};
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

int main(){
	int n,q;
	cin>>n>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	while(q--){
		int t,x,y;
		cin>>t>>x>>y;
		if(--t)cout<<query(1,1,n,x,y).tot<<endl;
		else{
			a[x]=y;
			update(1,1,n,x);
		}
	}
}

