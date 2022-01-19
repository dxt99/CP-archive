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

int n;
vl arr;

bool can(int val){
	int l=arr[n-2];
	int r=arr[n-3];
	int cur=arr[n-1];
	if(cur<val)return false;
	for(int i=4;i<=n;i++){
		ll cut=(cur-val)/3;
		cut=max(cut,(ll)0);
		cut=min(cut,arr[n-i+3]/3);
		l+=cut;
		r+=cut*2;
		//cout<<l<<" "<<val<<endl;
		if(l<val)return false;
		cur=l;
		l=r;
		r=arr[n-i];
	}
	ll cut=(cur-val)/3;
	cut=max(cut,(ll)0);
	cut=min(cut,arr[2]/3);
	l+=cut;
	r+=cut*2;
	//cout<<r<<"-"<<l<<endl;
	if(l<val||r<val)return false;
	return true;
} 

int find(int l, int r){
	if(l>=r)return l;
	ll mid=(l+r)/2;
	//printf(".%lld\n",mid);
	if(!can(mid)) return find(l,mid);
	else return find(mid+1,r);
}

void solve(){
	cin>>n;
	arr.clear();
	for(int i=0;i<n;i++){
		int x; cin>>x;
		arr.pb(x);
	}
	cout<<find(0,arr[n-1]+1)-1<<endl;
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

