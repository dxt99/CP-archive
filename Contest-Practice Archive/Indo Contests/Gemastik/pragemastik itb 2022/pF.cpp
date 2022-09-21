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

ll tri(pl a, pl b, pl c){
	ll ans = a.fs * (b.sd - c.sd);
	ans += b.fs * (c.sd - a.sd);
	ans += c.fs * (a.sd - b.sd);
	return abs(ans);
}
ll quad(pl a, pl b, pl c, pl d){
	ll ans = a.fs * (b.sd - d.sd);
	ans += b.fs * (c.sd - a.sd);
	ans += c.fs * (d.sd - b.sd);
	ans += d.fs * (a.sd - c.sd);
	return abs(ans);
}

void solve(){
	int n; cin>>n;
	minh h;
	vll arr(n);
	for(int i=0; i<n; i++){
		cin>>arr[i].fs;
		cin>>arr[i].sd;
	}
	for(int i=0; i<n; i++){
		// triangles
		h.push(tri(arr[i], arr[(i+1)%n], arr[(i+2)%n]));
		h.push(quad(arr[i], arr[(i+1)%n], arr[(i+2)%n], arr[(i+3)%n]));
	}
	h.pop();
	h.pop();
	cout<<h.top()<<endl;
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
