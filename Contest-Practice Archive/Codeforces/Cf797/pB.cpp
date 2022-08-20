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

void solve(){
	int n; cin>>n;
	vl a(n),b(n);
	for(ll& x: a)cin>>x;
	for(ll&x : b)cin>>x;
	
	ll num=a[0]-b[0];
	for(int i=0; i<n; i++){
		num = max(num, a[i]-b[i]);
	}
	for(ll& x: a)x-=num;
	for(int i=0;i<n;i++){
		a[i]=max(a[i],(ll)0);
		if(a[i]!=b[i]||num<0){
			cout<<"NO"<<endl;
			return;
		}
	}
	cout<<"YES"<<endl;
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
